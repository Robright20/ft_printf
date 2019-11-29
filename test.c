
/* Options struct for easy passing of Dragon4 options.
 *
 *   scientific - boolean controlling whether scientific notation is used
 *   digit_mode - whether to use unique or fixed fracional output
 *   cutoff_mode - whether 'precision' refers to toal digits, or digits past
 *                 the decimal point.
 *   precision - When negative, prints as many digits as needed for a unique
 *               number. When positive specifies the maximum number of
 *               significant digits to print.
 *   sign - whether to always show sign
 *   trim_mode - how to treat trailing 0s and '.'. See TrimMode comments.
 *   digits_left - pad characters to left of decimal point. -1 for no padding
 *   digits_right - pad characters to right of decimal point. -1 for no padding.
 *                  Padding adds whitespace until there are the specified
 *                  number characters to sides of decimal point. Applies after
 *                  trim_mode characters were removed. If digits_right is
 *                  positive and the decimal point was trimmed, decimal point
 *                  will be replaced by a whitespace character.
 *   exp_digits - Only affects scientific output. If positive, pads the
 *                exponent with 0s until there are this many digits. If
 *                negative, only use sufficient digits.
 */
typedef struct Dragon4_Options {
    npy_bool scientific;
    DigitMode digit_mode;
    CutoffMode cutoff_mode;
    npy_int32 precision;
    npy_bool sign;
    TrimMode trim_mode;
    npy_int32 digits_left;
    npy_int32 digits_right;
    npy_int32 exp_digits;
} Dragon4_Options;


#define BIGINT_DRAGON4_GROUPSIZE 7
typedef struct {
    BigInt bigints[BIGINT_DRAGON4_GROUPSIZE];
    char repr[16384];
} Dragon4_Scratch;


/*
 * Arguments:
 *   * bigints - memory to store all bigints needed (7) for dragon4 computation.
 *               The first BigInt should be filled in with the mantissa.
 *   * exponent - value exponent in base 2
 *   * mantissaBit - index of the highest set mantissa bit
 *   * hasUnequalMargins - is the high margin twice as large as the low margin
 *   * cutoffMode - how to interpret cutoffNumber: fractional or total digits?
 *   * cutoffNumber - cut off printing after this many digits. -1 for no cutoff
 *   * pOutBuffer - buffer to output into
 *   * bufferSize - maximum characters that can be printed to pOutBuffer
 *   * pOutExponent - the base 10 exponent of the first digit
 *
 * Returns the number of digits written to the output buffer.
 */
static npy_uint32	Dragon4(BigInt *bigints, const npy_int32 exponent,
        const npy_uint32 mantissaBit, const npy_bool hasUnequalMargins,
        const DigitMode digitMode, const CutoffMode cutoffMode,
        npy_int32 cutoffNumber, char *pOutBuffer,
        npy_uint32 bufferSize, npy_int32 *pOutExponent);


before doing the digit padding
000000000000000000000000000000000000000000010100001110100010011100101101111011000011111001010001 == 5693439482805841
000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000 == 4611686018427387904

before high bloc calcul
000000000000000000000000000000000100111100000011001010010000110101100010110100110110110001101001 == 5693439491395775593
000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000 == 4611686018427387904

after high bloc calcul
00001001 11100000 01100101 00100001 10101100 01011010 01101101 10001101 00100000 00000000 00000000 00000000
00001000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000


********************************************
small[i] == 1000000	        00000000 00000000 00000000 00000000 00000000000000000000000000000000 00000000000011110100001001000000
large == 4664065623848138	00000000 00000000 00000000 00000000 00000000000100001001000111110001 01100110101101111111010011001010
result == 1928283776	    00000000 00000000 00000000 00000000 00000000000000000000000000000000 01110010111011110100011010000000
                                                                             1100001111101011100 01110010111011110100011010000000
********************************************
********************************************
small == 1000000	            00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00001111 01000010 01000000
large == 4664065623848138	    00000000 00000000 00000000 00000000 00000000 00010000 10010001 11110001 01100110 10110111 11110100 11001010
result == 15486117273330992768	00000000 00000000 00000000 
111111001101011011101001101111011001110001110010111011110100011010000000
111111001101011011101001101111011001110001110010111011110100011010000000
********************************************

********************************************
small[i] == 1000000	            00000000 00000000 00000000 00000000 00000000000000000000000000000000 00000000000011110100001001000000
large == 4664065623848138	    00000000 00000000 00000000 00000000 00000000000100001001000111110001 01100110101101111111010011001010
result == 15486117273330992768	00000000 00000000 00000000 00000000 11010110111010011011110110011100 01110010111011110100011010000000
                                                           11111100 11010110111010011011110110011100
********************************************
