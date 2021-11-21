/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_case2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:55:41 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 13:55:02 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

void ft_case_d(t_global global, va_list arg, int **writtencharacters)
{
	long value;
	long long unsigned int test;
	char *output;
	char *value_str;
	output = ft_strdup("");
	
	if (global.int_state == 4)
	{
		test = va_arg(arg, long long int);
		value_str = ft_strdup(ft_basetoa(test, global));
	}
	if (global.int_state == 2 || global.int_state == 3)
	{
		value = (long int)va_arg(arg, int);
		if (value < 0)
		{
			value = -value;
			value = (UINT_MAX) - value + 1;
		}
		value_str = ft_strdup(ft_basetoa(value, global));
		/*printf(" hexvalue = %s ", value_str);*/
	}
	if (global.int_state == 1)
	{
		value = (long int)va_arg(arg, int);
		if (value < 0)
		{
			value = -value;
			value = (UINT_MAX) - value + 1;
		}
		value_str = ft_strdup(ft_itoa(value));
	}
	if (global.int_state == 0)
	{
		value = (long int)va_arg(arg, int);
		if (value < 0)
		{
			value = -value;
			global.value_negativ = 1;
		}
		value_str = ft_strdup(ft_itoa(value));
	}
	if (global.check_aste == 3 && global.check_dash != 1)
		return (ft_putstr(ft_intwidth03(value_str, global, &output, writtencharacters)));
	if (global.check_aste == 3 && global.check_dash == 1)
		return (ft_putstr(ft_intwidth04(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 0)
		return (ft_putstr(ft_intwidth00(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 1)
		return (ft_putstr(ft_intwidth01(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 2)
		return (ft_putstr(ft_intwidth02(value_str, global, &output, writtencharacters)));
	return;
}

void ft_case_s(t_global global, va_list arg, int **writtencharacters)
{
	char	*output;
	char	*value_str;
	char	temp;

	global.string = 1;
	value_str = ft_strdup("");
	if (global.int_state == 2)
	{	
		temp = (char)va_arg(arg, void*);
		value_str[0] = temp;
		if (value_str[0] == '\0')
		{
		global.width = global.width - 1;
		global.precision = global.precision - 1;
		}
	}
	if (global.int_state == 3)
		{
		/*value_str[0] = (char)va_arg(arg, void*);*/
		value_str[0] = '%';
		}
	else if (global.int_state != 2 && global.int_state != 3)
	value_str = (char *)va_arg(arg, char *);
	output = ft_strdup("");
	if (global.check_aste == 3 && global.check_dash != 1)
		return (ft_putstr(ft_strwidth03(value_str, global, &output, writtencharacters)));
	if (global.check_aste == 3 && global.check_dash == 1)
		return (ft_putstr(ft_strwidth04(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 0)
		return (ft_putstr(ft_intwidth00(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 1)
		return (ft_putstr(ft_intwidth01(value_str, global, &output, writtencharacters)));
	if (global.check_dash == 2)
		return (ft_putstr(ft_intwidth02(value_str, global, &output, writtencharacters)));
	return;
}
