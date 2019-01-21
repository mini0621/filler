/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:16:01 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/21 13:15:28 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include <stdlib.h>
#include "get_next_line.h"
#include "libftprintf.h"


#include <stdio.h>
#include <fcntl.h>


typedef struct	s_game
{
	int		x;
	int		y;
	char	p;
}				t_game;

typedef struct	s_piece
{
	int		x;
	int		y;
	char	**map;
}				t_piece;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

char	**get_game(t_game *game);
char	get_playernbr(char *line);
char	**cp_board(int x, int y, char **board);
char	**get_piecemap(int x, int y);
t_piece	*get_piece(t_piece *piece);


char	**init_map(int x, int y);
void	del_map(char **map);


int		skip_till(char *str, char **line, size_t len);
int		next_turn(t_game *game, char **board, t_piece *piece);
void	use_turn(int fd, t_game *game, char **board, t_piece *piece, t_coord *coord);

t_coord	*init_coord(t_coord *coord, int x, int y);
void	find_coord(t_game *game, char **board, t_piece *piece, t_coord *coord);
#endif
