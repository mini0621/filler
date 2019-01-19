/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/19 19:52:44 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int main(void)
{
	t_game	game;
	t_piece	piece;

	int fd;

	fd = open("txt", O_WRONLY);

	if (get_game(&game) == NULL || get_piece(&piece) == NULL)
		return (0);
	dprintf(fd, "piece %i %i %c", piece.x, piece.y, game.p);
	close(fd);
	return (0);
}