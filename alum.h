/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 00:28:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/09 05:33:38 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM_H
# define ALUM_H

# include <libft.h>
# include <time.h>

# define RED		"31"
# define GREEN		"32"
# define YELLOW		"33"
# define BLUE		"34"
# define PINK		"35"
# define GRBL		"36"
# define GREY		"37"
# define NO			"0"
# define C(X)		"\033["X"m"

# define D1_A (((l - 1) && (c + 1) < column - 1) &&\
				(tab[l][c] == tab[l - 2][c + 2]))

# define D1_B (((l - 2) && (c + 2) < column - 1) &&\
				(tab[l][c] == tab[l - 3][c + 3]))

# define D2_A ((l < line - 1 && c < column - 1) &&\
				(tab[l][c] == tab[l + 1][c + 1]))

# define D2_B (((l + 1) < line - 1 && (c + 1) < column - 1) &&\
				(tab[l][c] == tab[l + 2][c + 2]))

# define D2_C (((l + 2) < line - 1 && (c + 2) < column - 1) &&\
				(tab[l][c] == tab[l + 3][c + 3]))

# define CHECK_D2_A ((move + 2 < column && l + 1 < line - 1) &&\
				tab[l + 2][move + 2] == sym_r)

# define CHECK_D2_B ((move + 3 < column && l + 2 < line - 1) &&\
					tab[l + 3][move + 3] == sym_r)

void	alumin(int line, int column, char **tab);
void	play(int line, int column, char **tab, int player);
char	**init_map(int line, int column);
int		str_isdigit(char *str);
int		verif(char **tab, int line, int column);
int		errors(char *s1, char *s2);
void	free_tab(char **tab);
int		intelligence(char **tab, int column, int line);
int		chose_line(char **tab, int col);
int		check_col(char **tab, int move, int column);
int		check_line(char **tab, int move, int line);
int		check_d1(char **tab, int move, int line, int column);
int		check_d2(char **tab, int move, int line, int column);
void	free_mat(int **tab, int size);
int		check_up(char sym, int max, int up);
int		calc_up(char **tab, int move, int column, int l);
int		the_weight(int max, char sym);
int		choice(int max_l, int max_r, char *sym_l, char sym_r);

#endif /* ALUM_H */
