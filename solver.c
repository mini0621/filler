/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/20 18:25:35 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_coord	*init_coord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
	return (coord);
}

int		find_xo(int i, char *board, char p)
{
	while (board[i] != '\0' && board[i] != p)
		i++;
	return (i);
}

int		get_index(t_coord *coord, int w)
{
	return (coord->x + coord->y * w);	
}

t_coord	*get_coord(t_coord *coord, int index, int w)
{
	coord->x = index % w;
	coord->y = index / w;
	return (coord);
}
int		is_fit(int index, char *board, t_piece *piece)
{
	t_coord	pcoord;
	t_coord	bcoord;
	char	*map;
	int		i;

	map = piece->map;
	i = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '*')
				i++;
		init_coord(&pcoord, 0, 0);
		init_coord(&bcoord, index % game->x - i % piece->x, index / game->x + i / piece->x);
		while (map[get_index()] != '\0' && board[a] != '\0')
		{
			if (b != 0 && b % piece->x == 0)
				a += game->x - piece->x;
			if (a != index && map[b] != '.' && map[a] != '.')
				return (-1);
			if (a % game->x != game->x -1)
				a++;
			else 
			b++;
		}
	}
}

void	get_spot(t_game *game, char *board, t_piece *piece, t_coord *coord)
{
	int	index;

	index = get_index(0, board, game->p);

	coord->x = 8;
	coord->y = 2;
	return ;
}
