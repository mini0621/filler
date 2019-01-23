/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/23 15:14:49 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	print_map(int fd, char **map)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\n\n");
	while (map[i] != NULL)
	{
		ft_dprintf(fd, "%s\n", map[i]);
		i++;
	}
	ft_dprintf(fd,"\n\n");
}


int		main(void)
{
	t_game	game;
	t_piece	piece;
	char	**board;
	t_coord	dir;

	int fd;
	fd= open("txt", O_WRONLY);

	if ((board = get_game(&game)) == NULL || get_piece(&piece) == NULL)
		return (0);
	use_turn(fd, &game, board, &piece, choose_dir(board, game.p, &dir,&game));
	while (next_turn(&game, board, &piece) > -1)
	{
		print_map(fd, board);
		print_map(fd, piece.map);

		use_turn(fd, &game, board, &piece, &dir);
	}
	close(fd);
	return (0);
}

int		next_turn(t_game *game, char **board, t_piece *piece)
{
	char	*line;
	int		ret;

	if (cp_board(game->x, game->y, board) == NULL
		|| get_piece(piece) == NULL)
		return (-1);
	return (0);
}

void	use_turn(int fd, t_game *game, char **board, t_piece *piece, t_coord *dir)
{
	t_coord	coord;

	dprintf(fd," me : %c init dir x: %i y: %i toggle :%i\n",game->p,  dir->x, dir->y, game->toggle);
	if (find_coord(game, board, piece, &coord, dir) == NULL)
		init_coord(&coord, 0, 0);
	del_map(piece->map);
	ft_printf("%i %i\n", coord.y, coord.x);
	dprintf(fd, "%i %i dir x: %i y :%i, toggle: %i\n", coord.y, coord.x, dir->x, dir->y, game->toggle);
}
