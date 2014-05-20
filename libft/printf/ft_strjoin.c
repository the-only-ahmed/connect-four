/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:39:19 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 13:54:43 by ggarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*f_strjoin(char *s1, char *s2)
{
	int		length;
	char	*str;
	int		i;
	int		j;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	free(s2);
	str[i] = '\0';
	return (str);
}
