/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:01:55 by ldavids           #+#    #+#             */
/*   Updated: 2020/02/07 16:53:06 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int x)
{
	int		i;

	i = 0;
	if (x >= 10)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar('0' +  x % 10);
}

char 	*ft_puthexa(int x)
{
	int		i;
	char	*base = "0123456789ABCDEF";
	char	*temp;

	i = 0;
	temp = ft_strdup("                        ");
	while (x > 16)
	{
		x = x / 16;
		temp[i] = *(base + (x % 16));
		i++;
	}
	temp[i] = *(base + (x % 16));
	temp[i] = '\0';
	return (temp);
}

static int	ft_len(long int n)
{
	int				i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char		*ft_basetoa(long int n, t_global global)
{
	int		i;
	char			*str;
	char	base[17];
	char *temp;
	long int  cpy;
	
	if (global.int_state == 2 || global.int_state == 4)
	ft_strlcpy(base, "0123456789abcdef", 17);
	else
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	cpy = n;
	i = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = *(n % 16 + base);
		n = n / 16;
	}
	if (cpy != 0)
	{
		i = 0;
		while (str[i] == '0')
		i++;
		temp = ft_substr(str, i, ft_strlen(str));
		free(str);
		return (temp);
	}
	return (str);
}
