/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 05:05:02 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 09:35:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static int		left_side(char *sym, char **tab, int move, int l)
{
	int		max;

	max = 0;
	if (move - 1 >= 0 && tab[l][move - 1] != *sym)
	{
		*sym = tab[l][move - 1];
		max++;
		if (move - 2 >= 0 && tab[l][move - 2] == *sym)
		{
			max++;
			if (move - 3 >= 0 && tab[l][move - 3] == *sym)
				max++;
			else if (move - 3 >= 0 && tab[l][move - 3] == '.')
				max = 7;
		}
	}
	return (max);
}

static int		right_side(char *sym, char **tab, int move, int column)
{
	int		max;
	int		l;

	max = 0;
	l = chose_line(tab, move);
	if (move + 1 < column && tab[l][move + 1] != *sym)
	{
		*sym = tab[l][move + 1];
		max++;
		if (move + 2 < column && tab[l][move + 2] == *sym)
		{
			max++;
			if (move + 3 < column && tab[l][move + 3] == *sym)
				max++;
			else if (move + 3 < column && \
						tab[l][move + 3] == '.')
				max = 7;
		}
	}
	return (max);
}

int				check_col(char **tab, int move, int column)
{
	int		l;
	int		max_l;
	int		max_r;
	char	sym_l;
	char	sym_r;

	l = chose_line(tab, move);
	sym_l = '.';
	max_l = left_side(&sym_l, tab, move, l);
	sym_r = '.';
	max_r = right_side(&sym_r, tab, move, column);
	max_l = choice(max_l, max_r, &sym_l, sym_r);
	return (check_up(sym_l, max_l, calc_up(tab, move, column, l)));
}

int				check_line(char **tab, int move, int line)
{
	int		l;
	int		max;
	char	sym;

	max = 0;
	l = chose_line(tab, move);
	if (l == line - 1)
		return (0);
	sym = tab[l + 1][move];
	max++;
	if (l + 1 < line - 1 && tab[l + 2][move] == sym)
	{
		max++;
		if (l + 2 < line - 1 && tab[l + 3][move] == sym)
			max++;
	}
	return (check_up(sym, the_weight(max, sym), l + 1));
}
