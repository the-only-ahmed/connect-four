/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 03:42:25 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 13:01:51 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int		check_up(char sym, int max, int up)
{
	if (sym == 'o')
	{
		if (max == 10 || max == 15 || (max == 5 && up >= 2) ||\
				(max == 1 && up >= 3) || max == 7)
			return (max);
		return (0);
	}
	else
	{
		if (max == 20 || (max == 3 && up >= 2) || (max == 2 && up >= 3)\
			|| max == 7)
			return (max);
		return (0);
	}
}

int		calc_up(char **tab, int move, int column, int l)
{
	int		up;
	int		tmp;

	up = 0;
	tmp = move - 1;
	while (tmp >= 0 && tab[l][tmp] == '.')
	{
		tmp--;
		up++;
	}
	while (move < column && tab[l][move] == '.')
	{
		move++;
		up++;
	}
	return (up);
}

int		the_weight(int max, char sym)
{
	if (sym == 'o')
	{
		if (max == 2)
			max = 5;
		else if (max == 3)
			max = 10;
	}
	else if (sym == 'x')
	{
		if (max == 1)
			max = 2;
		else if (max == 2)
			max= 3;
		else
			max = 20;
	}
	return (max);
}

int		choice(int max_l, int max_r, char *sym_l, char sym_r)
{
	if (sym_r == *sym_l && *sym_l == '.')
		return (0);
	if (sym_r == *sym_l)
	{
		if (max_r + max_l >= 3)
		{
			if (sym_r == 'x')
				return (20);
			else
				return (15);
		}
		if (sym_r == 'x')
			return (3);
		else
			return (5);
	}
	if (max_l != 7)
		max_l = the_weight(max_l, *sym_l);
	if (max_r != 7)
		max_r = the_weight(max_r, sym_r);
	if (max_l > max_r)
		return (max_l);
	*sym_l = sym_r;
	return (max_r);
}
