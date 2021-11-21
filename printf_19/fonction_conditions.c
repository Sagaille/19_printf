/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:49:47 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/07 16:51:06 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

int ft_conditions(va_list arg, char *format, int *writtencharacters)
{
	t_global global;
	int buffer;

	global.value_negativ = 0;
	global.check_aste = 0;
	global.precision = 0;
	global.writtencharacters = 0;
	buffer = 0;
	global.width = 0;
	global.check_dash = 0;
	global.int_state = 0;
	global.spaceorzero = 0;
	/*global = *((t_global*)ft_calloc(1, 0));*/
	if (*format == '-')
	{
		global.check_dash = 1;
		format++;
		buffer++;
	}
	if (*format == '0')
	{
		if (global.check_dash != 1)
			global.check_dash = 2;
		format++;
		buffer++;
	}
	if (*format == '*')
	{
		if ((global.width = va_arg(arg, int)) < 0)
		{
			global.check_dash = 1;
			global.width = -global.width;
		}
		format++;
		buffer++;
		global.check_aste = 1;
	}
	if ((ft_isdigit(*format) == 1))
	{
		if (global.check_aste != 1)
			global.width = global.width + ft_atoi(format);
		while (ft_isdigit(*format))
		{
			format++;
			buffer++;
		}
	}
	if (*format == '.')
		ft_precision(&global, arg, &format, &buffer);
	if (*format == 's' || *format == 'c' || *format == '%')
		{
		if (*format == 'c')
			global.int_state = 2;
		if (*format == '%')
			global.int_state = 3;
		ft_case_s(global, arg, &writtencharacters);
		}
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X' || *format == 'p')
	{
		if (*format == 'u')
			global.int_state = 1;
		if (*format == 'x')
			global.int_state = 2;
		if (*format == 'X')
			global.int_state = 3;
		if (*format == 'p')
			global.int_state = 4;
		ft_case_d(global, arg, &writtencharacters);
	}
	*writtencharacters += global.writtencharacters;
	return (buffer);
}
