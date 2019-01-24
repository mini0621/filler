/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/24 16:59:07 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	get_positions(t_positions *me, t_positions *op, char **board, char p)
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
			//ft_printf("checking (%i, %i)\n", x, y);
			if (board[y][x] == p - 32 || board[y][x] == p)
			{
		//		ft_printf("found %c (%i, %i) max = %i\n", p, x, y, me->max_y);
				me->min_x = (me->min_x > x) ? x : me->min_x;
				me->min_y = (me->min_y > y) ? y : me->min_y;
				me->max_x = (me->max_x < x) ? x : me->max_x;
				me->max_y = (me->max_y < y) ? y : me->max_y;
			}
			if (board[y][x] == p2 - 32 || board[y][x] == p2)
			{
		//		ft_printf("found %c (%i, %i) max = %i\n", p2, x, y, op->max_y);
				op->min_x = (op->min_x > x) ? x : op->min_x;
				op->min_y = (op->min_y > y) ? y : op->min_y;
				op->max_x = (op->max_x < x) ? x : op->max_x;
				op->max_y = (op->max_y < y) ? y : op->max_y;
			}
			x++;
		}
		y++;
	}
}

void	init_positions(t_positions *pos, int x, int y)
{
	pos->min_x = x;
	pos->min_y = y;
	pos->max_x = 0;
	pos->max_y = 0;			
}

t_coord	*choose_dir(char **board, char p, t_coord *dir, t_game *game)
{
	t_positions	me;
	t_positions op;
	int			dis_op;
	int			dis_wa;

	init_positions(&me, game->x, game->y);
	init_positions(&op, game->x, game->y);
	get_positions(&me, &op, board, p);

	dir->x = (me.min_x <= op.min_x || me.max_x <= op.max_x) ? 1 : -1;
	dir->y = (me.min_y <= op.min_y || me.max_y <= op.max_y) ? 1 : -1;
	return (dir);
}

t_coord	*change_dir(t_game *game, char **board, t_coord *coord, t_coord *dir)
{
	t_positions	me;
	t_positions op;
	init_positions(&me, game->x, game->y);
	init_positions(&op, game->x, game->y);
	get_positions(&me, &op, board, game->p);
	if (game->toggle == 0 && ((dir->y > 0 && me.max_y - 5 >= op.min_y)
		|| (dir->y < 0 && me.min_y -5 <= op.max_y)))
		game->toggle = 1;
	if (game->toggle == 1 && ((me.max_y == game->y - 1 && me.min_y != 0)
	 || (me.max_y != game->y - 1 && me.min_y == 0)))
	{
		if (me.max_y == game->y - 1)
			dir->y = -1;
		game->toggle = 0;
	}
	if (game->toggle == 1 && (me.max_y == game->y - 1 && me.min_y == 0))
	{
		dir->y *= -1;
		game->toggle = 2;
	}
	if (game->toggle == 0 && (me.max_x == game->x - 1 ||  me.min_x == 0))
	{
		game->toggle = 3;
	}
	if (game->toggle ==  1 || game->toggle == 2)
	{
			dir->y *= -1; 
	}
//	if (game->toggle == 2)
//		game->toggle *= -1;
//	ft_printf("max (%i, %i) min (%i, %i)\n", me.max_x, me.max_y, me.min_x, me.min_y);
	return (NULL);
}

t_coord	*start_coord(t_coord *dir, t_coord *coord, int x, int y)
{
	if (dir->x == 1)
		coord->x = x;
	if (dir->x == -1)
		coord->x = -1;
	if (dir->y == 1)
		coord->y = y - 1;
	if (dir->y == -1)
		coord->y = 0;
	return (coord);
}
