/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:17:51 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/08 14:02:57 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int main ()
{
char	*str = "abcdefghijklm";
char	c = 'h';

ft_putchar(c);
ft_putchar('\n');
ft_putstr(str);
ft_putchar('\n');
ft_putnbr(0);
ft_putchar('\n');
ft_puthexa(6000);
ft_putchar('\n');
	return (0);
}