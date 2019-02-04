/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:19:15 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/30 18:43:50 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_coord	*choose_p_board(t_coord *coord, char **board,
		t_game *game, t_coord *dir)
{
	t_coord	index;
	t_coord lim;

	if (game->toggle == 2 || game->toggle == 3)
		return (choose_p_board2(coord, board, game, dir));
	coord->x = coord->x - dir->x;
	if (coord->x == game->x || coord->x == -1)
		init_coord(coord, (dir->x == 1) ? game->x - 1 : 0, coord->y - dir->y);
	lim.x = (dir->x > 0) ? -1 : game->x;
	init_coord(&index, coord->x, coord->y);
	lim.y = (dir->y > 0) ? -1 : game->y;
	while (index.y != lim.y)
	{
		while (index.x != lim.x)
		{
			if (board[index.y][index.x] == game->p
					|| board[index.y][index.x] == game->p - 32)
				return (init_coord(coord, index.x, index.y));
			index.x -= dir->x;
		}
		index.x = (dir->x < 0) ? 0 : game->x - 1;
		index.y -= dir->y;
	}
	return (NULL);
}

t_coord	*choose_p_board2(t_coord *coord, char **board,
		t_game *game, t_coord *dir)
{
	t_coord	index;
	t_coord lim;
	char	p;

	coord->y = coord->y - dir->y;
	if (coord->y == game->y || coord->y == -1)
		init_coord(coord, coord->x - dir->x, (dir->y == 1) ? game->y - 1 : 0);
	p = game->p;
	lim.x = (dir->x > 0) ? -1 : game->x;
	init_coord(&index, coord->x, coord->y);
	lim.y = (dir->y > 0) ? -1 : game->y;
	while (index.x != lim.x)
	{
		while (index.y != lim.y)
		{
			if (board[index.y][index.x] == p
					|| board[index.y][index.x] == p - 32)
				return (init_coord(coord, index.x, index.y));
			index.y -= dir->y;
		}
		index.y = (dir->y < 0) ? 0 : game->y - 1;
		index.x -= dir->x;
	}
	return (NULL);
}

t_coord	*choose_p_piece(t_coord *coord, t_piece *piece, t_coord *dir)
{
	t_coord	index;
	t_coord lim;

	coord->x += dir->x;
	if (coord->x == piece->x || coord->x == -1)
	{
		coord->y = coord->y + dir->y;
		coord->x = (dir->x == -1) ? piece->x - 1 : 0;
	}
	lim.x = (dir->x < 0) ? -1 : piece->x;
	init_coord(&index, coord->x, coord->y);
	lim.y = (dir->y < 0) ? -1 : piece->y;
	while (index.y != lim.y)
	{
		while (index.x != lim.x)
		{
			if (piece->map[index.y][index.x] == '*')
				return (init_coord(coord, index.x, index.y));
			index.x += dir->x;
		}
		index.x = (dir->x > 0) ? 0 : piece->x - 1;
		index.y += dir->y;
	}
	return (NULL);
}

t_coord	*choose_p_piece2(t_coord *coord, t_piece *piece, t_coord *dir)
{
	t_coord	index;
	t_coord lim;

	coord->y = coord->y + dir->y;
	if (coord->y == piece->y || coord->y == -1)
	{
		coord->x = coord->x + dir->x;
		coord->y = (dir->y == -1) ? piece->y - 1 : 0;
	}
	lim.x = (dir->x < 0) ? -1 : piece->x;
	init_coord(&index, coord->x, coord->y);
	lim.y = (dir->y < 0) ? -1 : piece->y;
	while (index.x != lim.x)
	{
		while (index.y != lim.y)
		{
			if (piece->map[index.y][index.x] == '*')
				return (init_coord(coord, index.x, index.y));
			index.y += dir->y;
		}
		index.y = (dir->y > 0) ? 0 : piece->y - 1;
		index.x += dir->x;
	}
	return (NULL);
}
