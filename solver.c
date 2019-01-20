/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:55:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/20 15:25:45 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_coord	*init_coord(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
	return (coord);
}


void	get_coord(t_game *game, char *board, t_piece *piece, t_coord *coord)
{
	coord->x = 2;
	coord->y = 8;
	return ;
}
