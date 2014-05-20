/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inteligence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:53:59 by ggarrigo          #+#    #+#             */
/*   Updated: 2014/03/09 09:29:42 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int			ft_max(int **tab, int size)
{
	int		max;
	int		i;
	int		move;

	max = tab[0][1];
	i = 0;
	while (i < size)
	{
		if (tab[i][1] >= max)
		{
			max = tab[i][1];
			move = tab[i][0];
		}
		i++;
	}
	return (move);
}

int			best_score(char **tab, int line, int column, int move)
{
	int		a;
	int		b;

	a = check_col(tab, move, column);
	b = check_line(tab, move, line);
	if (b > a)
		a = b;
	b = check_d1(tab, move, line, column);
	if (b > a)
		a = b;
	b = check_d2(tab, move, line, column);
	if (a > b)
		return (a);
	return (b);
}

int			**the_state(char **tab, int *p)
{
	int		**state;
	int		c;
	int		i;

	c = 0;
	while (tab[0][c])
	{
		if (tab[0][c] == '.')
			(*p)++;
		c++;
	}
	state = (int**)malloc(sizeof(int*) * (*p * 2));
	i = 0;
	c = 0;
	while (tab[0][c])
	{
		if (tab[0][c] == '.')
		{
			state[i] = (int*)malloc(sizeof(int) * 2);
			state[i][0] = c;
			i++;
		}
		c++;
	}
	return (state);
}

int			intelligence(char **tab, int column, int line)
{
	int			**state;
	int			p;
	int			i;

	p = 0;
	state = the_state(tab, &p);
	i = 0;
	while (i < p)
	{
		state[i][1] = best_score(tab, line, column, state[i][0]);
		i++;
	}
	i = ft_max(state, p);
	free_mat(state, p);
	return (i);
}
