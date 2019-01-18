/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:16:01 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/18 19:51:33 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

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
	char	*map;
}				t_piece;


char	*get_game(int fd, t_game *game);
char	get_playernbr(char *line);
char	*init_board(t_game *game, int fd);
char	*cp_board(int x, int y, char *board, int fd);

char	*get_pmap(int fd, int x, int y);
t_piece	*get_piece(int fd, t_piece *piece);
#endif
