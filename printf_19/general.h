/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:58:07 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/22 14:57:26 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

#include "Libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int x);
void			ft_puthexa(int x);
int				ft_printf(char * format, ...);
char			*ft_convert(unsigned int num, int base);
int				ft_intwidth(int x, int width, int **writtencharacters);
int				ft_strwidth(char *str, int width, int **writtencharacters);
int				ft_conditions(va_list arg, char *format, int *writtencharacters);
size_t			ft_displayInteger(int value);

typedef	struct 	s_point
{
int		charac;
int		string;
int		point;
int		deci;
int		integer;
int		unsign;
int		hexa;
int		hexaup;
}				va_struct;


#endif