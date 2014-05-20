/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:32:53 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 09:29:08 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static int		left_side(int move, char **tab, char *sym, int l)
{
	int		max;

	max = 0;
	if ((move > 0 && l) && tab[l - 1][move - 1] != *sym)
	{
		*sym = tab[l - 1][move - 1];
		max++;
		if ((move - 1 > 0 && l - 1 > 0) && tab[l - 2][move - 2] == *sym)
		{
			max++;
			if ((move - 2 > 0 && l - 2 > 0) && tab[l - 3][move - 3] == *sym)
				max++;
		}
	}
	return (max);
}

static int		der_max(int max_l, int max_r, char sym_l, char sym_r)
{
	max_l = the_weight(max_l, sym_l);
	max_r = the_weight(max_r, sym_r);
	if (max_l > max_r)
		return (max_l);
	return (max_r);
}

int				check_d2(char **tab, int move, int line, int column)
{
	int		l;
	int		max_l;
	int		max_r;
	char	sym_l;
	char	sym_r;

	l = chose_line(tab, move);
	sym_l = '.';
	max_l = left_side(move, tab, &sym_l, l);
	max_r = 0;
	sym_r = '.';
	if ((move + 1 < column && l < line - 1) && tab[l + 1][move + 1] != sym_r)
	{
		sym_r = tab[l + 1][move + 1];
		max_r++;
		if (CHECK_D2_A)
		{
			max_r++;
			if (CHECK_D2_B)
				max_r++;
		}
	}
	return (der_max(max_l, max_r, sym_l, sym_r));
}
