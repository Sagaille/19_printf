/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:55:08 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/30 13:21:47 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

char	*ft_intzero(int x, t_global global, char *output)
{
	int y;

	y = 0;
	y = ft_strlen(ft_itoa(x));
	if (global.value_negativ == 1)
	{
		ft_putchar('-');
		global.writtencharacters++;
		y++;
	}
	if (global.width > y)
	{
		global.width = global.width - y;
		while (global.width > 0)
		{
			ft_putchar('0');
			global.writtencharacters++;
			global.width--;
		}
	}
	return (output);
}
