/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:16:01 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/19 19:53:28 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include <stdlib.h>
#include "get_next_line.h"



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
	char	*map;
}				t_piece;


char	*get_game(t_game *game);
char	get_playernbr(char *line);
char	*init_board(t_game *game);
char	*cp_board(int x, int y, char *board);

char	*get_pmap(int x, int y);
t_piece	*get_piece(t_piece *piece);
#endif
