/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/23 17:27:40 by mnishimo         ###   ########.fr       */
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

	if (game->toggle == 1 || game->toggle == -2)
		return (choose_p_board2(coord, board, game, dir));
	coord->x = coord->x - dir->x;
	if (coord->x == game->x || coord->x == -1)
	{
		coord->y = coord->y - dir->y;
		coord->x = (dir->x == 1) ? game->x - 1: 0;
	}
	p = game->p;
	xlim = (dir->x > 0) ?  -1 : game->x;
	y = coord->y;
	x = coord->x;
	ylim = (dir->y >  0) ?  -1 : game->y;
	while (y != ylim)
	{
		while (x != xlim)
		{			
			if (board[y][x] == p || board[y][x] == p - 32)
				return (init_coord(coord, x, y));
			x = x - dir->x;
		}
		x = (dir->x < 0) ?  0: game->x - 1;	
		y = y - dir->y;
	}
	return (NULL);
}

t_coord *choose_p_board2(t_coord *coord, char **board, t_game *game, t_coord *dir)
{
	int		x;
	int 	y;
	int 	xlim;
	int 	ylim;
	char	p;
	
	coord->y = coord->y - dir->y;
	if (coord->y == game->y || coord->y == -1)
	{
		coord->x = coord->x - dir->x;
		coord->y = (dir->y == 1) ? game->y - 1: 0;
	}
	p = game->p;
	xlim = (dir->x > 0) ?  -1 : game->x;
	y = coord->y;
	x = coord->x;
	ylim = (dir->y >  0) ?  -1 : game->y;
	while (x != xlim)
	{
		while (y != ylim)
		{		
	//		ft_printf("checking x %i, y %i\n", x, y);
			if (board[y][x] == p || board[y][x] == p - 32)
				return (init_coord(coord, x, y));
			y = y - dir->y;
		}
		y = (dir->y < 0) ?  0: game->y - 1;	
		x = x - dir->x;
	}
	return (NULL);
}

t_coord *choose_p_piece(t_coord *coord, char **map, t_piece *piece, t_coord *dir)
{
	int		x;
	int 	y;
	int 	xlim;
	int 	ylim;
	
	coord->x = coord->x + dir->x;
	if (coord->x == piece->x || coord->x == -1)
	{
		coord->y = coord->y + dir->y;
		coord->x = (dir->x == -1) ? piece->x - 1: 0;
	}
	xlim = (dir->x < 0) ?  -1 : piece->x;
	y = coord->y;
	x = coord->x;
	ylim = (dir->y <  0) ?  -1 : piece->y;
	while (y != ylim)
	{
		while (x != xlim)
		{			
			if (map[y][x] == '*')
				return (init_coord(coord, x, y));
			x = x + dir->x;
		}
		x = (dir->x > 0) ?  0: piece->x - 1;	
		y = y + dir->y;
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
	if (coord->x < 0 || coord->y < 0)
		return (-1);	
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

t_coord	*find_coord(t_game *game, char **board, t_piece *piece,
		t_coord *coord, t_coord *dir)
{
	t_coord	base_b;
	t_coord	base_p;
	
	if (choose_p_board(start_coord(dir, &base_b, game->x, game->y), board, game, dir) == NULL)
		return (NULL);
	change_dir(game, board, &base_b, dir);
	if (choose_p_board(start_coord(dir, &base_b, game->x, game->y), board, game, dir) == NULL || choose_p_piece(start_piece(dir, &base_p, piece), piece->map, piece, dir) == NULL)
		return (NULL);
	//ft_printf("\nstart over coord x:%i, y:%i base_b x:%i, y:%i base_p x:%i, y:%i dir x:%i, y:%i   \n",coord->x, coord->y, base_b.x, base_b.y, base_p.x, base_p.y, dir->x, dir->y);
	init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
	while (coord->x > game->x -1 || coord->y > game->y - 1
			|| is_fit(coord, board, piece, &base_b) != 1)
	{
//	ft_printf("\nstart over coord x:%i, y:%i base_b x:%i, y:%i base_p x:%i, y:%i dir x:%i, y:%i   \n",coord->x, coord->y, base_b.x, base_b.y, base_p.x, base_p.y, dir->x, dir->y);
		init_coord(coord, base_b.x, base_b.y);
		if (choose_p_piece(&base_p, piece->map, piece, dir) == NULL)
		{
			if (choose_p_board(&base_b, board, game, dir) == NULL)
				return (NULL);
			choose_p_piece(start_piece(dir, &base_p, piece), piece->map, piece, dir);
		}
		init_coord(coord, base_b.x - base_p.x, base_b.y - base_p.y);
	}
	return (coord);
}
