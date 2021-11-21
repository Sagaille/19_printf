/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:51:27 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 13:44:22 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

void ft_width(t_global *global, char **output, int **writtencharacters, int y)
{
	if (global->spaceorzero == 1 && global->int_state == 4)
	{
		/*printf("donewidth ");*/
		{
		*output = ft_strjoin(*output, "0x");
		global->pointer = 1;
		}
	}
	if (global->width > y)
	{
		global->width = global->width - y;
		while (global->width > 0)
		{
			if (global->spaceorzero == 1)
				*output = ft_strjoin_spec(*output, "0");
			else
				*output = ft_strjoin_spec(*output, " ");
			**writtencharacters = **writtencharacters + 1;
			global->width--;
		}
	}
	return;
}

int ft_width_precision(t_global *global, char **output, int **writtencharacters, int y)
{
	int count;
/*printf("doneprewidth && %d", global->pointer);*/
	count = 0;
	if (global->int_state == 4 && global->pointer == 0)
	{
		*output = ft_strjoin(*output, "0x");
		global->pointer = 1;
	}
	if (global->precision > y)
	{
		global->precision = global->precision - y;
		while (global->precision > 0)
		{
			*output = ft_strjoin_spec(*output, "0");
			**writtencharacters = **writtencharacters + 1;
			global->precision--;
			count++;
		}
	}
	return (count);
}