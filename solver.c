/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/22 17:25:20 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	get_positions(t_coord *me, t_coord *op, char **board, char p)
{
	int		x;
	int 	y;
	char	p2;

	p2 = (p == 'x') ? 'o' : 'x';
	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			if (board[y][x] == p - 32)
				init_coord(me, x, y);
			if (board[y][x] == p2 - 32)
				init_coord(op, x, y);
			x++;
		}
		y++;
	}
}

t_coord	*choose_dir(char **board, char p, t_coord *dir)
{
	t_coord	me;
	t_coord op;

	get_positions(&me, &op, board, p);
	dir->x = (op.x - me.x < 0) ? -1 : 1;
	dir->y = (op.y - me.y < 0) ? -1 : 1;
	if (dir->x == 0)
		dir->x = 1;
	if (dir->y == 0)
		dir->y = 1;
	return (dir);
}

t_coord	*change_dir(t_game *game, char **board, t_coord *coord, t_coord *dir)
{
	char	op;

	op = (game->p == 'x') ? 'o' : 'x';

	
	//ft_printf("hi x: %i y : %i game; x %i, y%i dir x %i, y %i \n", coord->x, coord->y, game->x, game->y, dir->x, dir->y);
	if (dir->x == 1 && coord->x == game->x - 1)
		dir->x = -1;
	else if (dir->y == 1 && coord->y == game->y - 1)
		dir->y = -1;
	else if (dir->x == -1 && coord->x == 0)
		dir->x = 1;
	else if (dir->y == -1 && coord->y == 0)
		dir->y = 1;
	return (coord);
}

t_coord	*start_coord(t_coord *dir, t_coord *coord, t_game *game)
{
	if (dir->x == 1)
		coord->x = game->x - 1;
	if (dir->x == -1)
		coord->x = 0;
	if (dir->y == 1)
		coord->y = game->y - 1;
	if (dir->y == -1)
		coord->y = 0;
	return (coord);
}
