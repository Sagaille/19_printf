/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_annexe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:23:19 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/30 13:55:59 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general2.h"

char	*ft_strjoin_spec(char *s1, char *s2)
{
	int		index1;
	int		index2;
	char	*temp;

	index1 = (int)ft_strlen(s1);
	index2 = (int)ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	temp = ft_strdup(s1);
	free(s1);
	if (!(s1 = (char *)malloc(((index1 + index2) * sizeof(char)) + 1)))
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (temp[index1])
	{
		s1[index1] = temp[index1];
		index1++;
	}
	while (s2[index2])
		s1[index1++] = s2[index2++];
	s1[index1] = '\0';
	free(temp);
	return (s1);
}