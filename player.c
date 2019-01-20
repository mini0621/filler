/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/20 19:51:39 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int		main(void)
{
	t_game	game;
	t_piece	piece;
	char	*board;
	t_coord	coord;

	int fd = open("txt", O_WRONLY);

	if ((board = get_game(&game)) == NULL || get_piece(&piece) == NULL)
		return (0);
	use_turn(fd, &game, board, &piece, &coord);
	while (next_turn(&game, board, &piece) > 0)
		use_turn(fd, &game, board, &piece, &coord);
	//ft_dprintf(fd, "board %s\npiece%s\n", board, piece.map);
	close(fd);
	return (0);
}

int		next_turn(t_game *game, char *board, t_piece *piece)
{
	char	*line;
	int		ret;

	if (cp_board(game->x, game->y, board) == NULL
		|| get_piece(piece) == NULL)
		return (-1);
	return (0);
}

void	use_turn(int fd, t_game *game, char *board, t_piece *piece, t_coord *coord)
{
	init_coord(coord);
	get_coord(game, board, piece, coord);
	free(piece->map);
	ft_printf("%i %i\n", coord->x, coord->y);
}

int		skip_till(char *str, char **line, size_t len)
{
	int	ret;

	while ((ret = get_next_line(0, line)) > 0)
	{
		if (ft_strncmp(str, *line, len) == 0)
			break;
		free(*line);
	}
	if (ret == -1)
	{
		free(*line);
		return (ret);
	}
	return (ret);
}
