/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 00:23:35 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/08 07:39:17 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		main(int ac, char **av)
{
	int		line;
	int		column;
	int		player;
	char	**tab;

	if (ac != 3)
		return (-1);
	srand(time(NULL));
	if ((player = errors(av[1], av[2])) == -1)
		return (-1);
	line = ft_atoi(av[1]);
	column = ft_atoi(av[2]);
	tab = init_map(line, column);
	alumin(line, column, tab);
	play(line, column, tab, player);
	free_tab(tab);
	return (0);
}
