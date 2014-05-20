/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 05:36:35 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 13:30:55 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum.h"

static char		**add_move(int move, char **tab, int line, char sym)
{
	int		i;

	i = 0;
	while (i < line && tab[i][move] == '.')
		i++;
	tab[i - 1][move] = sym;
	return (tab);
}


static int		human(int column, char **tab, char *sym)
{
	char	*str;
	int		move;
	int		a;

	while ((a = get_next_line(0, &str)) != 2)
	{
		if (!a)
		{
			ft_printf("Arrête d'appuier sur (CTRL + D)\n");
			continue ;
		}
		move = ft_atoi(str) - 1;
		free(str);
		if (move >= 0 && move < column && tab[0][move] == '.')
			break ;
		ft_printf("Veuiller choisir un bon deplacement !\n");
	}
	*sym = 'o';
	return (move);
}

static int		IA(char **tab, int line, int column, char *sym)
{
	static int	i = 0;
	int			move;

	move = 0;
	if (!i)
	{
		while (tab[line - 1][i] == '.')
			i++;
		if (i == column)
			move = column / 2;
	}
	if (!move)
		move = intelligence(tab, column, line);
	*sym = 'x';
	return (move);
}

void			play(int line, int column, char **tab, int player)
{
	int		move;
	char	sym;
	char	*str;
	int		win;

	while ((win = verif(tab, line, column)) == 1)
	{
		ft_putchar('\n');
		if (player)
			move = human(column, tab, &sym);
		else
			move = IA(tab, line, column, &sym);
		tab = add_move(move, tab, line, sym);
		player = (player)? 0 : 1;
		alumin(line, column, tab);
	}
	if (!win)
	{
		str = (player)? ft_strdup("CPU") : ft_strdup("PLAYER");
		ft_printf("%s won !\n", str);
		free(str);
	}
	else
		ft_printf("TIE GAME !\n");
}
