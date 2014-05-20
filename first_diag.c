/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 05:19:36 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 06:35:16 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static int		right_side(int move, int column, char **tab, char *sym)
{
	int		max;
	int		l;

	max = 0;
	l = chose_line(tab, move);
	if ((move + 1 < column && l) && tab[l - 1][move + 1] != *sym)
	{
		*sym = tab[l - 1][move + 1];
		max++;
		if ((move + 2 < column && l - 1 > 0) && tab[l - 2][move + 2] == *sym)
		{
			max++;
			if ((move + 3 < column && l - 2 > 0) && \
					tab[l - 3][move + 3] == *sym)
				max++;
		}
	}
	return (max);
}

static int		left_side(int move, int line, char **tab, char *sym)
{
	int		max;
	int		l;

	max = 0;
	l = chose_line(tab, move);
	if ((move > 0 && l < line - 1) && tab[l + 1][move - 1] != *sym)
	{
		*sym = tab[l + 1][move - 1];
		max++;
		if ((move - 1 > 0 && l + 1 < line - 1) && tab[l + 2][move - 2] == *sym)
		{
			max++;
			if ((move - 2 > 0 && l + 2 < line - 1) && \
					tab[l + 3][move - 3] == *sym)
				max++;
		}
	}
	return (max);
}

int		check_d1(char **tab, int move, int line, int column)
{
	int		max_l;
	int		max_r;
	char	sym_l;
	char	sym_r;

	sym_l = '.';
	max_l = left_side(move, line, tab, &sym_l);
	sym_r = '.';
	max_r = right_side(move, column, tab, &sym_r);
	max_l = the_weight(max_l, sym_l);
	max_r = the_weight(max_r, sym_r);
	if (max_l > max_r)
		return (max_l);
	return (max_r);
}
