/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:02:25 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/30 13:55:54 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

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