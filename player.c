/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/30 18:41:00 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int		main(void)
{
	t_game	game;
	t_piece	piece;
	t_coord	dir;

	if ((game.board = get_game(&game)) == NULL)
		return (0);
	if (get_piece(&piece) == NULL)
	{
		del_map(game.board);
		return (0);
	}
	use_turn(&game, &piece, choose_dir(game.board, game.p, &dir, &game));
	while (next_turn(&game, game.board, &piece) > -1)
		use_turn(&game, &piece, &dir);
	del_map(game.board);
	return (0);
}

t_coord	*choose_dir(char **board, char p, t_coord *dir, t_game *game)
{
	t_positions	me;
	t_positions op;

	init_positions(&me, &op, game->x, game->y);
	get_positions(&me, &op, board, p);
	dir->x = (me.min.x <= op.min.x || me.max.x <= op.max.x) ? 1 : -1;
	dir->y = (me.min.y <= op.min.y || me.max.y <= op.max.y) ? 1 : -1;
	return (dir);
}

int		next_turn(t_game *game, char **board, t_piece *piece)
{
	if (cp_board(game->x, game->y, board) == NULL
			|| get_piece(piece) == NULL)
		return (-1);
	return (0);
}

void	use_turn(t_game *game, t_piece *piece, t_coord *dir)
{
	t_coord	coord;

	if (find_coord(game, piece, &coord, dir) == NULL)
		init_coord(&coord, 0, 0);
	del_map(piece->map);
	ft_printf("%i %i\n", coord.y, coord.x);
}
