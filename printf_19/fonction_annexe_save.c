/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_annexe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:49:47 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/22 15:30:59 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int ft_conditions(va_list arg, char *format, int *writtencharacters)
{
	int width;
	int check_aste;
	int check_negativ = 0;
	int buffer;

	buffer = 0;
	check_aste = 0;
	width = 0;
	if (*format == '-')
	{
		check_negativ = 1;
		format++;
	}
	if (*format == '*')
	{
		width = va_arg(arg, int);
		format++;
		buffer++;
		check_aste = 1;
	}
	while ((ft_isdigit(*format) == 1))
	{
		/*if (check_aste == 1)
			return (-1000);*/
		width = width + ft_atoi(format);
		format++;
		buffer++;
	}
	if (*format == 'd')
	{
		if (check_negativ == 0)
		{
		int integerValue = ft_intwidth(va_arg(arg, int), width, &writtencharacters);
		*writtencharacters += ft_displayInteger(integerValue);
		}
		else if (check_negativ == 1)
		{
		int integerValue = va_arg(arg, int);
		*writtencharacters += ft_displayInteger(integerValue);
		ft_intwidth(integerValue, width, &writtencharacters);
		}
	}
	if (*format == 's')
	{
		char *string = (char *)va_arg(arg, char *);
		width = ft_strwidth(string, width, &writtencharacters);
		while (*string != '\0')
		{
			ft_putchar(*string++);
			*writtencharacters = *writtencharacters + 1;
		}
	}
	return (buffer);
}

int ft_intwidth(int x, int width, int **writtencharacters)
{
	int y;

	y = 0;
	y = ft_strlen(ft_itoa(x));
	if (width > y)
	{
		width = width - y;
		while (width > 0)
		{
			ft_putchar(' ');
			**writtencharacters = **writtencharacters + 1;
			width--;
		}
	}
	return (x);
}

int ft_strwidth(char *str, int width, int **writtencharacters)
{
	int y;

	y = 0;
	y = ft_strlen(str);
	if (width > y)
	{
		width = width - y;
		while (width > 0)
		{
			ft_putchar(' ');
			**writtencharacters = **writtencharacters + 1;
			width--;
		}
	}
	return (0);
}