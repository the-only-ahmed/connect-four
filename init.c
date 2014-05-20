/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 03:16:26 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 03:36:23 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

char	**init_map(int line, int column)
{
	char	**tab;
	int		l;
	int		c;

	tab = (char**)malloc(sizeof(char*) * ((line * (column + 1) + 1)));
	l = 0;
	while (l < line)
	{
		c = 0;
		tab[l] = (char*)malloc(sizeof(char) * (column + 1));
		while (c < column)
		{
			tab[l][c] = '.';
			c++;
		}
		tab[l][c] = '\0';
		l++;
	}
	tab[l] = NULL;
	return (tab);
}

int		str_isdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		errors(char *s1, char *s2)
{
	int		player;

	if (!str_isdigit(s1) || !str_isdigit(s2))
	{
		ft_printf("Map Error !\n");
		return (-1);
	}
	if (ft_atoi(s1) < 6 || ft_atoi(s2) < 7)
	{
		ft_printf("Map Error !\n");
		return (-1);
	}
	player = (rand() % 2);
	if (player)
		ft_printf("player first\n");
	else
		ft_printf("computer first\n");
	return (player);
}

int		chose_line(char **tab, int col)
{
	int		l;

	l = 0;
	while (tab[l + 1] && tab[l][col] == '.')
		l++;
	if (tab[l][col] != '.')
		l--;
	return (l);
}
