/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/18 19:33:00 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_piece	*get_piece(int fd, t_piece *piece)
{
	char	*line;
	int		i;

	if (get_next_line(fd, &line) <= 0)
		return (NULL);
	if (ft_strncmp(line, "Piece", 5) != 0)
		return (NULL);
	piece->x = atoi(line + 7);
	i = 7;
	while (line[i] != ' ')
		i++;
	piece->y = atoi(line + i);
	free(line);
	piece->map = get_pmap(fd, piece->x, piece->y);
}

char	*get_pmap(int fd, int x, int y)
{
	int		i;
	char	*ret;

	if ((ret = ft_strnew(piece->x * piece->y)) == NULL)
		return (NULL);
	i = 0;
	while (i < piece->y)
	{
		if (get_next_line(fd, &line) = -1)
		{
			free(piece->map);
			return (NULL);
		}
		ft_strcat(ret, line);
		i++;
	}
	return (ret);
}
