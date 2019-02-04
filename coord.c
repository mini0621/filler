/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/28 13:39:03 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_coord	*init_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
	return (coord);
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

int		is_fit(t_coord *coord, char **board, t_piece *piece, t_coord *base_b)
{
	t_coord	i;

	i.y = 0;
	while (piece->map[i.y] != NULL)
	{
		i.x = 0;
		if (board[coord->y + i.y] == NULL)
			return ((is_empty(piece->map, i.y, 'y') == 1) ? 1 : -1);
		while (piece->map[i.y][i.x] != '\0')
		{
			if (board[coord->y + i.y][coord->x + i.x] == '\0'
					&& is_empty(piece->map, i.x, 'x') != 1)
				return (-1);
			if (board[coord->y + i.y][coord->x + i.x] == '\0')
				break ;
			if (piece->map[i.y][i.x] == '*'
				&& board[coord->y + i.y][coord->x + i.x] != '.'
				&& !(coord->y + i.y == base_b->y
					&& coord->x + i.x == base_b->x))
				return (-1);
			i.x++;
		}
		i.y++;
	}
	return (1);
}

t_coord	*find_coord(t_game *game, t_piece *piece, t_coord *coord, t_coord *dir)
{
	t_coord	base_b;
	t_coord	base_p;

	if (choose_p_board(start_coord(dir, &base_b, game->x, game->y),
				game->board, game, dir) == NULL)
		return (NULL);
	change_dir(game, game->board, dir);
	if (choose_p_board(start_coord(dir, &base_b, game->x, game->y),
		game->board, game, dir) == NULL || choose_p_piece(start_piece(dir,
				&base_p, piece), piece, dir) == NULL)
		return (NULL);
	init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
	while (coord->x > game->x - 1 || coord->y > game->y - 1 || coord->x < 0
			|| coord->y < 0 || is_fit(coord, game->board, piece, &base_b) != 1)
	{
		init_coord(coord, base_b.x, base_b.y);
		if (choose_p_piece(&base_p, piece, dir) == NULL)
		{
			if (choose_p_board(&base_b, game->board, game, dir) == NULL)
				return (NULL);
			choose_p_piece(start_piece(dir, &base_p, piece), piece, dir);
		}
		init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
	}
	return (coord);
}
