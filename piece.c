/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/19 19:53:48 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_piece	*get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) < 0)
		return (NULL);	
	if (ft_strncmp(line, "Piece", 5) != 0)
		return (NULL);
	piece->y = atoi(line + 6);
	i = 6;
	while (line[i] != ' ')
		i++;
	piece->x = atoi(line + i);
	free(line);
	piece->map = get_pmap(piece->x, piece->y);
	return (piece);
}

char	*get_pmap(int x, int y)
{
	int		i;
	char	*ret;
	char	*line;

	if ((ret = ft_strnew(x * y)) == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (get_next_line(0, &line) == -1)
		{
			free(ret);
			return (NULL);
		}
		ft_strcat(ret, line);
		i++;
	}
	return (ret);
}
