/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strwidth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:54:14 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/30 13:55:58 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

int ft_strwidth(char *str, t_global global, int **writtencharacters, int count)
{
	int y;

	if (count != 0)
		y = count;
	if (count == 0)
		y = ft_strlen(str);
	if (global.width > y)
	{
		global.width = global.width - y;
		while (global.width > 0)
		{
			ft_putchar(' ');
			**writtencharacters = **writtencharacters + 1;
			global.width--;
		}
	}
	return (0);
}