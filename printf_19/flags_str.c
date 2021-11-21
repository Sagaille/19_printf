/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:11:44 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 14:21:42 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

char *ft_strwidth03(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	y = ft_strlen(value_str);
	/*printf("str03 ");*/
	**writtencharacters += y;
	if (global.precision < y)
	{
		ft_width(&global, output, writtencharacters, global.precision);
		*output = ft_strjoin_spec(*output, ft_substr(value_str, 0, global.precision));
		global = *((t_global*)ft_calloc(1, 0));
		return (*output);
	}
	else
	{
		ft_width(&global, output, writtencharacters, y);
		*output = ft_strjoin_spec(*output, value_str);
		global = *((t_global*)ft_calloc(1, 0));
		return (*output);
	}
	return (NULL);
}

char *ft_strwidth04(char *value_str, t_global global, char **output, int **writtencharacters)
{
	int y;

	*output = ft_strdup("");
	y = ft_strlen(value_str);
	**writtencharacters += y;
	/*printf("str04 ");*/
	if (global.precision < y)
	{
		*output = ft_strjoin_spec(*output, ft_substr(value_str, 0, global.precision));
		ft_width(&global, output, writtencharacters, global.precision);
		global = *((t_global*)ft_calloc(1, 0));
		return (*output);
	}
	*output = ft_strjoin_spec(*output, value_str);
	ft_width(&global, output, writtencharacters, ft_strlen(value_str));
	global = *((t_global*)ft_calloc(1, 0));
	return (*output);
}