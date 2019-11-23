#include "bigInt.h"
#include <assert.h>

#define c_BigInt_Maxtab  1023

#if 0
#define DEBUG_ASSERT(stmnt) assert(stmnt)
#else
#define DEBUG_ASSERT(stmnt) do {} while(0)
#endif
static inline t_uint64
bitmask_u64(t_uint32 n)
{
	    return ~(~((t_uint64)0) << n);
}

// static inline t_uint32
// bitmask_u32(t_uint32 n)
// {
// 	    return ~(~((t_uint32)0) << n);
// }


t_uint32	BigInt_DivideWithRemainder_MaxQuotient9(t_bigint *dividend, const t_bigint *divisor)
{
	t_uint32 length, quotient;
	const t_uint32 *finalDivisorBlock;
	t_uint32 *finalDividendBlock;

	/*
	 * Check that the divisor has been correctly shifted into range and that it
	 * is not smaller than the dividend in length.
	 */
	DEBUG_ASSERT(!divisor->length == 0 &&
			divisor->tab[divisor->length-1] >= 8 &&
			divisor->tab[divisor->length-1] < bitmask_u64(32) &&
			dividend->length <= divisor->length);

	/*
	 * If the dividend is smaller than the divisor, the quotient is zero and the
	 * divisor is already the remainder.
	 */
	length = divisor->length;
	if (dividend->length < divisor->length) {
		return 0;
	}

	finalDivisorBlock = divisor->tab + length - 1;
	finalDividendBlock = dividend->tab + length - 1;

	/*
	 * Compute an estimated quotient based on the high block value. This will
	 * either match the actual quotient or undershoot by one.
	 */
	quotient = *finalDividendBlock / (*finalDivisorBlock + 1);
	DEBUG_ASSERT(quotient <= 9);

	/* Divide out the estimated quotient */
	if (quotient != 0) {
		/* dividend = dividend - divisor*quotient */
		const t_uint32 *divisorCur = divisor->tab;
		t_uint32 *dividendCur = dividend->tab;

		t_uint64 borrow = 0;
		t_uint64 carry = 0;
		do {
			t_uint64 difference, product;

			product = (t_uint64)*divisorCur * (t_uint64)quotient + carry;
			carry = product >> 32;

			difference = (t_uint64)*dividendCur
				- (product & bitmask_u64(32)) - borrow;
			borrow = (difference >> 32) & 1;

			*dividendCur = difference & bitmask_u64(32);

			++divisorCur;
			++dividendCur;
		} while(divisorCur <= finalDivisorBlock);

		/* remove all leading zero tab from dividend */
		while (length > 0 && dividend->tab[length - 1] == 0) {
			--length;
		}

		dividend->length = length;
	}

	/*
	 * If the dividend is still larger than the divisor, we overshot our
	 * estimate quotient. To correct, we increment the quotient and subtract one
	 * more divisor from the dividend.
	 */
	if (ft_bigint_compare(*dividend, *divisor) >= 0) {
		/* dividend = dividend - divisor */
		const t_uint32 *divisorCur = divisor->tab;
		t_uint32 *dividendCur = dividend->tab;
		t_uint64 borrow = 0;

		++quotient;

		do {
			t_uint64 difference = (t_uint64)*dividendCur
				- (t_uint64)*divisorCur - borrow;
			borrow = (difference >> 32) & 1;

			*dividendCur = difference & bitmask_u64(32);

			++divisorCur;
			++dividendCur;
		} while(divisorCur <= finalDivisorBlock);

		/* remove all leading zero tab from dividend */
		while (length > 0 && dividend->tab[length - 1] == 0) {
			--length;
		}

		dividend->length = length;
	}

	return quotient;
}
