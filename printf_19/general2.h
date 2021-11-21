/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:58:07 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/12 11:47:36 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL2_H
# define GENERAL2_H

#include "Libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef	struct	s_point
{
int		width;
int		writtencharacters;
int		check_dash;
int		check_aste;
int		value_negativ;
int		precision;
int		spaceorzero;
va_list	arg;
int		charac;
int		string;
int		int_state;
int		pointer;
}				t_global;

void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int x);
char			*ft_puthexa(int x);
int				ft_printf(char * format, ...);
char			*ft_convert(unsigned int num, int base);
char			*ft_basetoa(long int n, t_global global);

char			*ft_intwidth00(char *value_str, t_global global, char **output, int **writtencharacters);
char			*ft_intwidth01(char *value_str, t_global global, char **output, int **writtencharacters);
char			*ft_intwidth02(char *value_str, t_global global, char **output, int **writtencharacters);
char			*ft_intwidth03(char *value_str, t_global global, char **output, int **writtencharacters);
char			*ft_intwidth04(char *value_str, t_global global, char **output, int **writtencharacters);

char			*ft_strwidth03(char *value_str, t_global global, char **output, int **writtencharacters);
char			*ft_strwidth04(char *value_str, t_global global, char **output, int **writtencharacters);

int				ft_strwidth(char *str, t_global global, int **writtencharacters, int count);
char			*ft_intzero(int x, t_global global, char *output);
int				ft_conditions(va_list arg, char *format, int *writtencharacters);
size_t			ft_displayInteger(int value);
void			ft_width(t_global *global, char **output, int **writtencharacters, int y);
int				ft_width_precision(t_global *global, char **output, int **writtencharacters, int y);


int				ft_precision(t_global *global, va_list arg, char **format, int *buffer);
void			ft_case_d(t_global global, va_list arg, int **writtencharacters);
void			ft_case_s(t_global global, va_list arg, int **writtencharacters);

char			*ft_strjoin_spec(char *str1, char *str2);



#endif