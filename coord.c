/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/22 00:39:53 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_coord	*init_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
	return (coord);
}

t_coord *choose_p_board(t_coord *coord, char **board, t_game *game, t_coord *dir)
{
	int		x;
	int 	y;
	int 	xlim;
	int 	ylim;
	char	p;
	
	//change_dir(game, board, coord, dir);
	coord->x = coord->x - dir->x;
	if (coord->x == game->x || coord->x == -1)
	{
		coord->y = coord->y - dir->y;
		coord->x = (dir->x == 1) ? game->x - 1: 0;
	}
	//ft_printf("x: %i y: %i dir x: %i, y %i\n", coord->x, coord->y, dir->x, dir->y);
	p = game->p;
	xlim = (dir->x > 0) ?  -1 : game->x - 1;
	y = coord->y;
	ylim = (dir->y >  0) ?  -1 : game->y;
	while (y != ylim)
	{
		x = coord->x;
		while (x != xlim)
		{
//			ft_printf("x: %i y: %i\n", x, y);
			if (board[y][x] == p || board[y][x] == p - 32)
				return (init_coord(coord, x, y));
			x = x - dir->x;
		}
		y = y - dir->y;
	}
	return (NULL);
}

t_coord *choose_p_piece(t_coord *coord, char **map)
{
	int	x;
	int	y;

	x = coord->x + 1;
	if (map[coord->y][x] == '\0')
	{
		x = 0;
		y = coord->y + 1;
	}
	else
		y = coord->y;
	
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '*')
				return (init_coord(coord, x, y));
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}

int		is_fit(t_coord *coord, char **board, t_piece *piece, t_coord *base_b)
{
	int		x;
	int		y;
	char	**map;

	map = piece->map;
	y = 0;
	while(map[y] != NULL)
	{
		x = 0;
		if (board[coord->y + y] == NULL)
				return ((is_empty(map, y, 'y') == 1) ? 1 : -1);
		while (map[y][x] != '\0')
		{
			if (board[coord->y + y][coord->x + x] == '\0'
					&& is_empty(map, x, 'x') != 1)
				return (-1);
			if (board[coord->y + y][coord->x + x] == '\0')
				break;
			if (map[y][x] == '*' && board[coord->y + y][coord->x + x] != '.'
				&& !(coord->y + y == base_b->y && coord->x + x == base_b->x))
				return (-1);
			x++;
		}
		y++;	
	}
	return (1);
}

void	find_coord(t_game *game, char **board, t_piece *piece,
		t_coord *coord, t_coord *dir)
{
	t_coord	base_b;
	t_coord	base_p;
	
	if (choose_p_board(start_coord(dir, &base_b, game), board, game, dir) == NULL)
		return ;
//	ft_printf("starting from x:%i, y:%i\n", base_b.x, base_b.y);
	if (choose_p_piece(init_coord(&base_p, -1, 0), piece->map) == NULL)
		return ;
//	ft_printf("starting from x:%i, y:%i\n", base_p.x, base_p.y);
	init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
	while (coord->x < 0 || coord->y < 0 
			||is_fit(coord, board, piece, &base_b) != 1)
	{
		if (choose_p_piece(&base_p, piece->map) == NULL)
		{
			if (choose_p_board(&base_b, board, game, dir) == NULL)
				return ;
//		ft_printf("\nnow boardx:%i, y:%i\n", base_b.x, base_b.y);
			choose_p_piece(init_coord(&base_p, -1, 0), piece->map);
		}
//		ft_printf("piece is at x:%i, y:%i\n", base_p.x, base_p.y);
		init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
//		printf("will check x:%i, y:%i\n", coord->x, coord->y);
	}
//	printf("starting from x:%i, y:%i\n", coord->x, coord->y);
	return ;
}
