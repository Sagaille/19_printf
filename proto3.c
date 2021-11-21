/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:44:40 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 14:22:03 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "general2.h"

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

/*int main(int argc, char *argv[])
{
	int a;
	int	*b;
	

	a = 120;
	b = &a;
	
	printf("%d\n", ft_printf("Begin %-*i End\n", 3, 120));
	printf("%d\n", printf("Begin %-*i End\n", 3, 120));
	printf("%d\n", ft_printf("Begin %10i End\n", -123));
	printf("%d\n", printf("Begin %10i End\n", -123));
	printf("%d\n", ft_printf("Begin %-10i%010i End\n", -123, 150));
	printf("%d\n", printf("Begin %-10i%010i End\n", -123, 150));
	printf("%d\n", ft_printf("Begin %010i End\n", -123));
	printf("%d\n", printf("Begin %010i End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5i End\n", -123));
	printf("%d\n", printf("Begin %-10.5i End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5i End\n", -123));
	printf("%d\n", printf("Begin %-10.5i End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5i End\n", 123));
	printf("%d\n", printf("Begin %-10.5i End\n", 123));
	printf("%d\n", ft_printf("Begin %10.5i End\n", 123));
	printf("%d\n", printf("Begin %10.5i End\n", 123));
	printf("%d\n", ft_printf("Begin %5.2i End\n", 123));
	printf("%d\n", printf("Begin %5.2i End\n", 123));
	printf("%d\n", ft_printf("Begin %8.5i End\n", 123456789));
	printf("%d\n", printf("Begin %8.5i End\n", 123456789));

	printf("%d\n", ft_printf("Begin %s End\n", "pute"));
	printf("%d\n", printf("Begin %s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %s middle End\n", "-totouuu"));
	printf("%d\n", printf("Begin %s middle End\n", "-totouuu"));
	printf("%d\n", ft_printf("Begin %-*s End\n", 3, "pute"));
	printf("%d\n", printf("Begin %-*s End\n", 3, "pute"));
	printf("%d\n", ft_printf("Begin %10s End\n", "pute"));
	printf("%d\n", printf("Begin %10s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %-10d%5s%%%%10d%% End\n", -123, "pute", 100));
	printf("%d\n", printf("Begin %-10d%5s%%%%10d%% End\n", -123, "pute", 100));
	printf("%d\n", ft_printf("Begin %010s End\n", "pute"));
	printf("%d\n", printf("Begin %010s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %1.2s End\n", "pute"));
	printf("%d\n", printf("Begin %1.2s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %-10.5s End\n", "pute"));
	printf("%d\n", printf("Begin %-10.5s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %15.5s End\n", "pute"));
	printf("%d\n", printf("Begin %15.5s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %10.5s End\n", "pute"));
	printf("%d\n", printf("Begin %10.5s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %5.2s End\n", "pute"));
	printf("%d\n", printf("Begin %5.2s End\n", "pute"));
	printf("%d\n", ft_printf("Begin %-80.5s End\n", "puteputeeeeee"));
	printf("%d\n", printf("Begin %-80.5s End\n", "puteputeeeeee"));

	printf("%d\n", ft_printf("Begin %-*u End\n", 3, 120));
	printf("%d\n", printf("Begin %-*u End\n", 3, 120));
	printf("%d\n", ft_printf("Begin %10u End\n", -123));
	printf("%d\n", printf("Begin %10u End\n", -123));
	printf("%d\n", ft_printf("Begin %-10u%010u End\n", -123, 150));
	printf("%d\n", printf("Begin %-10u%010u End\n", -123, 150));
	printf("%d\n", ft_printf("Begin %010u End\n", -123));
	printf("%d\n", printf("Begin %010u End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5u End\n", -123));
	printf("%d\n", printf("Begin %-10.5u End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5u End\n", -123));
	printf("%d\n", printf("Begin %-10.5u End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5u End\n", 123));
	printf("%d\n", printf("Begin %-10.5u End\n", 123));
	printf("%d\n", ft_printf("Begin %10.5u End\n", 123));
	printf("%d\n", printf("Begin %10.5u End\n", 123));
	printf("%d\n", ft_printf("Begin %5.2u End\n", 123));
	printf("%d\n", printf("Begin %5.2u End\n", 123));
	printf("%d\n", ft_printf("Begin %8.5u End\n", 123456789));
	printf("%d\n", printf("Begin %8.5u End\n", 123456789));

	printf("%d\n", ft_printf("Begin %-*x End\n", 3, 1));
	printf("%d\n", printf("Begin %-*x End\n", 3, 1));
	printf("%d\n", ft_printf("Begin %10X End\n", -1));
	printf("%d\n", printf("Begin %10X End\n", -1));
	printf("%d\n", ft_printf("Begin %-10X%010X End\n", 123, -150));
	printf("%d\n", printf("Begin %-10X%010X End\n", 123, -150));
	printf("%d\n", ft_printf("Begin %010X End\n", -9230015151));
	printf("%d\n", printf("Begin %010X End\n", -9230015151));
	printf("%d\n", ft_printf("Begin %-10.5X End\n", -123));
	printf("%d\n", printf("Begin %-10.5X End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5X End\n", -123));
	printf("%d\n", printf("Begin %-10.5X End\n", -123));
	printf("%d\n", ft_printf("Begin %-10.5x End\n", 123));
	printf("%d\n", printf("Begin %-10.5x End\n", 123));
	printf("%d\n", ft_printf("Begin %10.5x End\n", 123));
	printf("%d\n", printf("Begin %10.5x End\n", 123));
	printf("%d\n", ft_printf("Begin %5.2x End\n", 123));
	printf("%d\n", printf("Begin %5.2x End\n", 123));
	printf("%d\n", ft_printf("Begin %8.5x End\n", 123456789));
	printf("%d\n", printf("Begin %8.5x End\n", 123456789));

	printf("TESTS %%\n");
	printf("%d\n", ft_printf("Begin %% End\n"));
	printf("%d\n", printf("Begin %% End\n"));
	printf("%d\n", ft_printf("Begin %% middle End\n"));
	printf("%d\n", printf("Begin %% middle End\n"));
	printf("%d\n", ft_printf("Begin %-*% End\n", 3));
	printf("%d\n", printf("Begin %-*% End\n", 3));
	printf("%d\n", ft_printf("Begin %10% End\n"));
	printf("%d\n", printf("Begin %10% End\n"));
	printf("%d\n", ft_printf("Begin %-10d%010% End\n", -123));
	printf("%d\n", printf("Begin %-10d%010% End\n", -123));
	printf("%d\n", ft_printf("Begin %010% End\n"));
	printf("%d\n", printf("Begin %010% End\n"));
	printf("%d\n", ft_printf("Begin %1.2% End\n"));
	printf("%d\n", printf("Begin %1.2% End\n"));
	printf("%d\n", ft_printf("Begin %-10.5% End\n"));
	printf("%d\n", printf("Begin %-10.5% End\n"));
	printf("%d\n", ft_printf("Begin %15.5% End\n"));
	printf("%d\n", printf("Begin %15.5% End\n"));
	printf("%d\n", ft_printf("Begin %10.5% End\n"));
	printf("%d\n", printf("Begin %10.5% End\n"));
	printf("%d\n", ft_printf("Begin %5.2% End\n"));
	printf("%d\n", printf("Begin %5.2% End\n"));
	printf("%d\n", ft_printf("Begin %-80.5% End\n"));
	printf("%d\n", printf("Begin %-80.5% End\n"));

	printf("%d\n", printf("TESTS C"));
	printf("%d\n", ft_printf("Begin %% End\n"));
	printf("%d\n", printf("Begin %% End\n"));
	printf("%d\n", ft_printf("Begin %c middle End\n", 'c'));
	printf("%d\n", printf("Begin %c middle End\n", 'c'));
	printf("%d\n", ft_printf("Begin %-*c End\n", 3, 'c'));
	printf("%d\n", printf("Begin %-*c End\n", 3, 'c'));
	printf("%d\n", ft_printf("Begin %10c End\n", 'c'));
	printf("%d\n", printf("Begin %10c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %-10d%010c End\n", -123, 'c'));
	printf("%d\n", printf("Begin %-10d%010c End\n", -123, 'c'));
	printf("%d\n", ft_printf("Begin %010c End\n", 'c'));
	printf("%d\n", printf("Begin %010c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %1.2c End\n", 'c'));
	printf("%d\n", printf("Begin %1.2c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %-10.5c End\n", 'c'));
	printf("%d\n", printf("Begin %-10.5c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %15.5c End\n", 'c'));
	printf("%d\n", printf("Begin %15.5c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %10.5c End\n", 'c'));
	printf("%d\n", printf("Begin %10.5c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %5.2c End\n", 'c'));
	printf("%d\n", printf("Begin %5.2c End\n", 'c'));
	printf("%d\n", ft_printf("Begin %-80.5c End\n", 'c'));
	printf("%d\n", printf("Begin %-80.5c End\n",'c'));
	printf("%d\n", ft_printf("Begin %5.2c End\n", '\0'));
	printf("%d\n", printf("Begin %5.2c End\n", '\0'));
	printf("%d\n", ft_printf("Begin %c End\n", '\0'));
	printf("%d\n", printf("Begin %c End\n",'\0'));
	printf("%d\n", ft_printf("Begin %-10d%010c End\n", -123, '\0'));
	printf("%d\n", printf("Begin %-10d%010c End\n", -123, '\0'));

	printf("\nTESTS *\n\n");
	printf("%d\n", ft_printf("Begin %p End\n", b));
	printf("%d\n", printf("Begin %p End\n", b));
	printf("%d\n", ft_printf("Begin %10p End\n", b));
	printf("%d\n", printf("Begin %10p End\n", b));
	printf("%d\n", ft_printf("Begin %-10p%010p End\n", b, 150));
	printf("%d\n", printf("Begin %-10p%010p End\n", b, 150));
	printf("%d\n", ft_printf("Begin %010p End\n", b));
	printf("%d\n", printf("Begin %010p End\n", b));
	printf("%d\n", ft_printf("Begin %-10.5p End\n", b));
	printf("%d\n", printf("Begin %-10.5p End\n", b));
	printf("%d\n", ft_printf("Begin %-0.7p End\n", b));
	printf("%d\n", printf("Begin %-0.7p End\n", b));
	printf("%d\n", ft_printf("Begin %-10.15p End\n", b));
	printf("%d\n", printf("Begin %-10.15p End\n", b));
	printf("%d\n", ft_printf("Begin %10.15p End\n", b));
	printf("%d\n", printf("Begin %10.15p End\n", b));
	printf("%d\n", ft_printf("Begin %5.2p End\n", b));
	printf("%d\n", printf("Begin %5.2p End\n", b));
	printf("%d\n", ft_printf("Begin %14.10p End\n", 123456789));
	printf("%d\n", printf("Begin %14.10p End\n", 123456789));
	printf("%d\n", ft_printf("Begin %0.0p End\n", b));
	printf("%d\n", printf("Begin %0.0p End\n", b));
	printf("%d\n", ft_printf("Begin %0.0p End\n", b));
	printf("%d\n", printf("Begin %0.0p End\n", b));
	printf("%d\n", ft_printf("Begin %0.0p End\n", 123456789));
	printf("%d\n", printf("Begin %0.0p End\n", 123456789));
	return 0;
}*/