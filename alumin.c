/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alumin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 00:30:17 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 13:09:19 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static void		roof(int column)
{
	int		i;

	i = 0;
	while (i < column)
	{
		ft_putstr(C(YELLOW)"----");
		i++;
	}
	ft_putstr("-\n"C(NO));
}

static void		positions(int column)
{
	int		i;

	i = 0;
	while (i < column)
	{
		if (i < 9)
			ft_putchar(' ');
		ft_printf(C(PINK)" %d ", i + 1);
		i++;
	}
	ft_putstr("\n"C(NO));
}

static void		move_print(char sym, int *c, int i, int column)
{
	if (i % 2 == 0)
	{
		if (sym == '.')
			ft_putchar(' ');
		else if (sym == 'o')
			ft_printf(C(GREEN)"O"C(NO));
		else
			ft_printf(C(RED)"O"C(NO));
		(*c)++;
		if ((*c) < column)
			ft_putchar(' ');
	}
	else
		ft_printf(C(YELLOW)"| "C(NO));
}

void			alumin(int line, int column, char **tab)
{
	int		l;
	int		c;
	int		i;

	l = 0;
	while (l <= line)
	{
		i = 0;
		c = 0;
		roof(column);
		while (l < line && c < column)
		{
			i++;
			move_print(tab[l][c], &c, i, column);
		}
		if (l < line)
			ft_printf(C(YELLOW)" |\n"C(NO));
		l++;
	}
	positions(column);
}
