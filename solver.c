/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/29 18:04:09 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	get_positions(t_positions *me, t_positions *op, char **board, char p)
{
	int	x;
	int	y;

	y = 0;
	while (board[y] != NULL)
	{
		x = 0;
		while (board[y][x] != '\0')
		{
			if (board[y][x] == p - 32 || board[y][x] == p)
				store_positions(me, x, y);
			if (board[y][x] != '.' && board[y][x] != p - 32 && board[y][x] != p)
				store_positions(op, x, y);
			x++;
		}
		y++;
	}
}

void	store_positions(t_positions *pos, int x, int y)
{
	pos->min.x = (pos->min.x > x) ? x : pos->min.x;
	pos->min.y = (pos->min.y > y) ? y : pos->min.y;
	pos->max.x = (pos->max.x < x) ? x : pos->max.x;
	pos->max.y = (pos->max.y < y) ? y : pos->max.y;
}

void	init_positions(t_positions *me, t_positions *op, int x, int y)
{
	init_coord(&me->min, x, y);
	init_coord(&me->max, 0, 0);
	init_coord(&op->min, x, y);
	init_coord(&op->max, 0, 0);
}

void	change_toggle(t_positions *me, t_coord *dir, t_game *game)
{
	if (game->toggle == 1 && ((me->max.y == game->y - 1 && me->min.y != 0)
		|| (me->max.y != game->y - 1 && me->min.y == 0)))
	{
		if (me->min.y == 0)
			dir->y = 1;
		else
			dir->y = -1;
		game->toggle = 0;
	}
	if (game->toggle == 1 && (me->max.y == game->y - 1 && me->min.y == 0))
	{
		dir->y *= -1;
		game->toggle = 2;
	}
}

t_coord	*change_dir(t_game *game, char **board, t_coord *dir)
{
	t_positions	me;
	t_positions op;

	init_positions(&me, &op, game->x, game->y);
	get_positions(&me, &op, board, game->p);
	if (game->toggle == 0 && ((dir->y > 0 && me.max.y - 5 >= op.min.y)
		|| (dir->y < 0 && me.min.y - 5 <= op.max.y)))
		game->toggle = 1;
	if (game->toggle == 2 && ((dir->x < 0 && op.max.x >= me.min.x)
		|| (dir->x > 0 && op.min.x <= me.max.x)))
		dir->x *= -1;
	change_toggle(&me, dir, game);
	if (game->toggle == 2 && ((me.max.x == game->x - 1)
			|| (me.min.x == 0)))
		game->toggle = 3;
	if (game->toggle == 1 || game->toggle == 2)
		dir->y *= -1;
	return (NULL);
}
