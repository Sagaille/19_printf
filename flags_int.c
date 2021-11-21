/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:53:08 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 14:21:26 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

char *ft_intwidth00(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	if (global.int_state == 4)
	value_str = ft_strjoin("0x", value_str);
	y = ft_strlen(value_str);
	**writtencharacters += y;
	/*printf("int00 ");*/
	if (global.value_negativ == 1)
		global.width--;
	ft_width(&global, output, writtencharacters, y);
	if (global.value_negativ == 1)
	{
		*output = ft_strjoin_spec(*output, "-");
		**writtencharacters = **writtencharacters + 1;
	}
	*output = ft_strjoin_spec(*output, value_str);
	/*ft_memset(&global, 0, sizeof(t_global));*/
	global = *((t_global*)ft_calloc(1, 0));
	return (*output);
}

char *ft_intwidth01(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	if (global.int_state == 4)
	value_str = ft_strjoin("0x", value_str);
	y = ft_strlen(value_str);
	**writtencharacters += y;
	/*printf("int01 ");*/
	if (global.value_negativ == 1)
	{
		free(*output);
		*output = ft_strdup("-");
		**writtencharacters = **writtencharacters + 1;
		global.width--;
	}
	*output = ft_strjoin_spec(*output, value_str);
	ft_width(&global, output, writtencharacters, y);
	global = *((t_global*)ft_calloc(1, 0));
	return (*output);
}

char *ft_intwidth02(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	y = ft_strlen(value_str);
	if (global.int_state == 4)
	global.width = global.width - 2;
	**writtencharacters += y;
	/*printf("int02 ");*/
	if (global.value_negativ == 1)
	{
		free(*output);
		*output = ft_strdup("-");
		**writtencharacters = **writtencharacters + 1;
		global.width--;
	}
	global.spaceorzero = 1;
	ft_width(&global, output, writtencharacters, y);
	*output = ft_strjoin_spec(*output, value_str);
	global = *((t_global*)ft_calloc(1, 0));
	return (*output);
}

char *ft_intwidth03(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	y = ft_strlen(value_str);
	/*printf("int03 ");*/
	if (global.int_state == 4)
	global.width = global.width - 2;
	**writtencharacters += y;
	if (global.precision > global.width)
	{
		if (global.value_negativ == 1)
		{
			free(*output);
			*output = ft_strdup("-");
		}
		ft_width_precision(&global, output, writtencharacters, y);
		*output = ft_strjoin_spec(*output, value_str);
		global = *((t_global*)ft_calloc(1, 0));
		return (*output);
	}
	else if (global.width > global.precision)
	{
		if (global.precision < y)
		{
			global.precision = 0;
			ft_width(&global, output, writtencharacters, y);
		}
		if (global.value_negativ == 1)
			global.width = global.width - 1;
		if (global.width > y)
		ft_width(&global, output, writtencharacters, y + global.precision - y);
		if (global.value_negativ == 1)
		{
			*output = ft_strjoin_spec(*output, "-");
			**writtencharacters = **writtencharacters + 1;
		}
		if (global.precision > y)
		{
			ft_width_precision(&global, output, writtencharacters, y);
		}
		if (global.pointer == 0 && global.int_state == 4)
		value_str = ft_strjoin("0x", value_str);
		*output = ft_strjoin_spec(*output, value_str);
		global = *((t_global*)ft_calloc(1, 0));
		return (*output);
	}
	return (NULL);
}

char *ft_intwidth04(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;
	int count;

	count = 0;
	*output = ft_strdup("");
	y = ft_strlen(value_str);
	if (global.int_state == 4)
	y = y + 2;
	**writtencharacters += y;
	if (global.precision < y)
		global.precision = 0;
	/*printf("int04 ");*/
	if (global.value_negativ == 1)
	{
		*output = ft_strdup("-");
		global.width = global.width - 1;
	}
	if (global.precision > y)
	{
		count = ft_width_precision(&global, output, writtencharacters, ft_strlen(value_str));
	}
	if (global.pointer == 0 && global.int_state == 4)
		value_str = ft_strjoin("0x", value_str);
	*output = ft_strjoin_spec(*output, value_str);
	ft_width(&global, output, writtencharacters, ft_strlen(value_str) + count);
	global = *((t_global*)ft_calloc(1, 0));
	return (*output);
}