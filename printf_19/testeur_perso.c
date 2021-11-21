/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur_perso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:10:34 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/07 13:37:19 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

int main ()
{
	int y;
	int ret;
	int x = 5;
	int z = 10;

y = -77;
char c = 0;
char *p = "abcdefg";
printf("%%vefesfsefe");
putchar('\n');
printf("%cvefesfsefe", 'c');
putchar('\n');

printf("%-15.3%");
putchar('\n');
printf("%-15c", 'c');
putchar('\n');
printf("%015%");
putchar('\n');
printf("%015c", 'c');
putchar('\n');
printf("%-015%");
putchar('\n');
printf("%-015c", 'c');
putchar('\n');
printf("%*.*%", 20, 10);
putchar('\n');
printf("%*.*c", 20, 10, 'c');
putchar('\n');
/*
printf("%c", c);
putchar('\n');
printf("%020u", y);
putchar('\n');
printf("%010u", y);
putchar('\n');
printf("%*i", 16, y);
putchar('\n');
printf("%13.2i", y);
putchar('\n');
printf("%13.*i", 5, y);
putchar('\n');
printf("%c", y);
putchar('\n');
printf("Begin %s %10% End\n", "toto", 421);
printf("Begin %s %*% End\n", "toto", 42, 10);*/


	return(0);
}