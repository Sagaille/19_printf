/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:36:57 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/07 17:36:54 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

int		ft_precision(t_global *global, va_list arg, char **format, int *buffer)
{
global->precision = 0;
*format = *format + 1;
*buffer = *buffer + 1;
global->check_aste = 3;
if (**format == '*')
	{
		global->precision = va_arg(arg, int);
		*format = *format + 1;
		*buffer = *buffer + 1;
	}
if (**format == '-')
{
*format = *format + 1;
*buffer = *buffer + 1;
global->check_aste = 4;
}
if (ft_isdigit(**format) == 1)
	{
		global->precision = global->precision + ft_atoi(*format);
		while (ft_isdigit(**format))
		{
		*format = *format + 1;
		*buffer = *buffer + 1;
		}
	}
if (global->precision <= 0 || global->check_aste == 4)
{
		global->check_aste = 4;
		global->precision = 0;
}
/*if (global->check_dash == 2)*/
return (0);
}