#include "bigint.h"


/*
** 		** les tach a fire pour le bigint **
**
**	 creat the bigint type 
**	 creat		- bigInt_addition()
** 			- bigInt_multiplication()
** 			- int_to_bigInt()
** 	calcule of 2^52	and convert this to bigInt type ===> a
** 	calcule of 2^(exp - 1075)  usning bigInt type	===> e
** 	convert the mantissa to bingInt					===> m 
** 	calcule this in big int  (a + m) * e
*/

t_int32		ft_round_thatshit(t_bigint_compound *compound, char *buff, char **cur, t_uint32 out_number)
{
	t_int32	value;
	char	*buff_cur;

	ft_bigint_shiftleft(&compound->v_num, 1);
	value = ft_bigint_compare(compound->v_num, compound->v_dom);
	buff_cur = *cur;
	if (value == 0)
		value = ((out_number & 1) == 1);
	if (value > 0)
	{
		if (out_number == 9)
			while (TRUE)
			{
				if (buff == buff_cur)
				{
					*buff_cur = '1';
					return (1);
				}
				buff_cur--;
				if (*buff_cur != '9')
				{
					*buff_cur = (*buff_cur + 1);	
					//buff_cur++;
					break;	
				}
			}
		//while (*(++buff_cur) != '\0')
		//	*buff_cur = '0';
	}
	else
		*buff_cur = (out_number + '0');
	*cur = buff_cur;
	return (0);
}

/*
** ---------------------------------------------------------------------------
**	buff << functions << v_num and v_dom
**
**	 struct compound {
**		bigint	v_num
**		bigint	v_dom
**		bigint 	temp1
**		bigint	temp2
**		t_int32	bigbit
**		}
*/	

int mini_dragon4(t_bigint_compound *compound, t_int32 exponent, char *buff, t_uint32 max_len, t_int32 *print_expo, t_int32 cuttoff_num)
{
	t_int32		digit;
	char		*buff_cur;
	double 		log10_2 = 0.30102999566398119521373889472449;
	t_int32	cuttoff_expo;
	t_bigint	temp;
	t_uint32	out_number;
	t_uint32	hibloc;

	*print_expo = 0;
	/*-------------------------------------------------*/
	if (ft_is_zero(compound->temp1) == TRUE)
	{
		buff[0] = '0';
		return (1);
	}
	/*-------------------------------------------------*/
	// initialize v_num and v_dom
	ft_bigint_copy(&compound->v_num, &compound->temp1);
	if (exponent > 0)
	{
		// e = 2^(exp - 1075)
		ft_bigint_shiftleft(&compound->v_num, exponent);
		ft_uint32_to_bigint(1, &compound->v_dom);
		//dec_pos = 100;
	}
	else if (exponent < 0)
	{
		//n = 1075 - exp;
		ft_uint32_to_bigint(1, &compound->v_dom);
		ft_bigint_shiftleft(&compound->v_dom, -exponent);
	}
	/*-------------------------------------------------*/
	digit = (t_int32)((double)(compound->bigbit + exponent) * log10_2 - 0.69) + 1;
	if (cuttoff_num >= 0 && digit <= -cuttoff_num)
		digit = -cuttoff_num + 1;
	/*-------------------------------------------------*/
		// v_dom = v_dom * 10^digit or v_num = v_num*10^-digit
	if (digit > 0)
		ft_bigint_power10(&compound->v_dom, digit);
	else if (digit < 0)
		ft_bigint_power10(&compound->v_num, -digit);
	/*-------------------------------------------------*/
	if (ft_bigint_compare(compound->v_num, compound->v_dom) >= 0)
		digit++;
	else
		ft_bigint_power10(&compound->v_num, 1);
	/* ------------------------------------------------- */
	cuttoff_expo = digit - max_len;
	if ((cuttoff_num >= 0) && (-cuttoff_num > cuttoff_expo))
			cuttoff_expo = -cuttoff_num;
	*print_expo = digit - 1;
	/*-------------------------------------------------*/
	hibloc = compound->v_dom.tab[compound->v_dom.length - 1];
	if (hibloc < 8 || hibloc > 429496729)
	{
		t_uint32 hibloc_log2, shift;
		hibloc_log2 = logbase2_32(hibloc);
		shift = (32 + 27 - hibloc_log2) % 32;
		ft_bigint_shiftleft(&compound->v_num, shift);
		ft_bigint_shiftleft(&compound->v_dom, shift);
	}
	/*-------------------------------------------------*/
	buff_cur = buff;
	while (1)
	{
		digit = digit - 1;
		out_number = ft_bigint_divid(&compound->v_num, &compound->v_dom);
		if (out_number >= 10)
			printf("out_number error == %d;\n", out_number);
		if (compound->v_num.length == 0 || digit == cuttoff_expo)
			break;
		*buff_cur = (char)(out_number + '0');
		buff_cur++;
		ft_bigint_copy(&temp, &compound->v_num);
		ft_bigint_mult_int(&compound->v_num, temp, 10);
	}
	*print_expo += ft_round_thatshit(compound, buff, &buff_cur, out_number);
	buff_cur++;
	*buff_cur = '\0';
	return (buff_cur - buff);
}
