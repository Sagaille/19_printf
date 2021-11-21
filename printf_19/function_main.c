/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:00:15 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/21 12:10:28 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

char *convert(unsigned int, int);

int ft_printf(char *format, ...)
{
	char *currentchar;
	int i;
	char ch;
	char *s;
	int x;
	int writtenchar;

	x = 0;
	writtenchar = 0;

	currentchar = ft_strdup(format);
	while (currentchar[x] && currentchar[x] != '%')
	{
		putchar(currentchar[x]);
		x++;
	}

	va_list arg;
	va_start(arg, format);

	while (currentchar[x])
	{
		if (currentchar[x] == 'c')
		{
			i = va_arg(arg, int);
			ft_putchar(i);
			break;
		}
		if (currentchar[x] == 'd')
		{
			i = va_arg(arg, int);
			if (i < 0)
			{
				i = -i;
				ft_putchar('-');
			}
			ft_putstr(ft_convert(i, 10));
			break;
		}
		if (currentchar[x] == 's')
		{
			s = va_arg(arg, char *);
			ft_putstr(s);
			break;
		}
		if (currentchar[x] == 'x')
		{
			i = va_arg(arg, unsigned int);
			ft_putstr(ft_convert(i, 16));
			break;
		}
		x++;
	}

	va_end(arg);
	return (0);
}

char *ft_convert(unsigned int num, int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	while (num != 0)
	{
		*--ptr = Representation[num % base];
		num = base;
	}

	return (ptr);
}

int main()
{
	char x = 'k';
	char *str = "abcdefg";
	int i = -77;
	printf("HELLO WORLD%s%d", str, i);
	ft_putchar('\n');
	ft_printf("HELLO WORLD");
	ft_putchar('\n');
	return 0;
}