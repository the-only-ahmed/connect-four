/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:41:59 by ggarrigo          #+#    #+#             */
/*   Updated: 2014/03/09 03:35:21 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

int			verif_d1(char **tab, int line, int column)
{
	int		l;
	int		c;

	l = 0;
	while (l < line)
	{
		c = 0;
		while (c < column)
		{
			if (tab[l][c] != '.')
			{
				if ((l && c < column - 1) && (tab[l][c] == tab[l - 1][c + 1]))
				{
					if (D1_A)
					{
						if (D1_B)
							return (0);
					}
				}
			}
			c++;
		}
		l++;
	}
	return (1);
}

int		verif_d2(char **tab, int line, int column)
{
	int		l;
	int		c;

	l = 0;
	while (l < line)
	{
		c = 0;
		while (c < column)
		{
			if (tab[l][c] != '.')
			{
				if (D2_A)
				{
					if (D2_B)
					{
						if (D2_C)
							return (0);
					}
				}
			}
			c++;
		}
		l++;
	}
	return (1);
}

int		verif_c(char **tab, int line, int column)
{
	int		l;
	int		c;
	int		max;

	l = 0;
	while (l < line)
	{
		max = 0;
		c = 0;
		while (c < column)
		{
			if (tab[l][c] != '.')
			{
				if (c && tab[l][c - 1] == tab[l][c])
					max++;
				else
					max = 0;
			}
			if (max == 3)
				return (0);
			c++;
		}
		l++;
	}
	return (1);
}

int		verif_l(char **tab, int line, int column)
{
	int		l;
	int		c;
	int		max;

	c = 0;
	while (c < column)
	{
		max = 0;
		l = 0;
		while (l < line)
		{
			if (tab[l][c] != '.')
			{
				if (l && tab[l - 1][c] == tab[l][c])
					max++;
				else
					max = 0;
			}
			if (max == 3)
				return (0);
			l++;
		}
		c++;
	}
	return (1);
}

int		verif(char **tab, int line, int column)
{
	int			c;

	if (!verif_c(tab, line, column) || !verif_l(tab, line, column))
		return (0);
	if (!verif_d1(tab, line, column) || !verif_d2(tab, line, column))
		return (0);
	c = 0;
	while (c < column)
	{
		if (tab[0][c] == '.')
			return (1);
		c++;
	}
	return (-1);
}
