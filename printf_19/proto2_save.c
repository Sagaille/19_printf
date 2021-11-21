/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:44:40 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/22 15:28:46 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "general.h"

size_t ft_displayInteger(int value)
{
	if (value < 10)
	{
		ft_putchar(0x30 + value);
		return 1;
	}
	size_t size = ft_displayInteger(value / 10);
	ft_putchar(0x30 + value % 10);
	return 1 + size;
}

int ft_printf(char *format, ...)
{
	int buffer;
	va_list arg;
	va_start(arg, format);
	int writtencharacters;
	char currentchar;

	buffer = 0;
	writtencharacters = 0;
	while ((currentchar = *format) != '\0')
	{
		if (currentchar != '%')
		{
			ft_putchar(currentchar);
			writtencharacters++;
		}
		else if (currentchar == '%')
		{
			format++;
			{
				buffer = ft_conditions(arg, format, &writtencharacters);
				while (buffer-- > 0)
					format++;
			}
		}
		format++;
	}
	va_end(arg);
	return (writtencharacters);
}

int main(int argc, char *argv[])
{
	int a;

	a = 120;
	/*printf("%d\n", ft_printf("Begin %10s End\n", "Middle"));
	printf("%d\n", printf("Begin %10s End\n", "Middle"));*/
	printf("%d\n", ft_printf("Begin %*d End\n", 12, 123));
	printf("%d\n", printf("Begin %*d End\n", 12, 123));
	/*printf("%d\n", ft_printf("Begin End\n"));
	printf("%d\n", printf("Begin End\n"));
	printf("%d\n", ft_printf("Begin %s middle %d %d End\n", "totouuu", 421, a));
	printf("%d\n", printf("Begin %s middle %d %d End\n", "totouuu", 421, a));*/

	return 0;
}