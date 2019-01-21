/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:13:46 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/21 22:41:05 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_piece	*get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (skip_till("Piece", &line, 5) < 1)
		return (NULL);
	piece->y = atoi(line + 6);
	i = 6;
	while (line[i] != ' ')
		i++;
	piece->x = atoi(line + i);
	free(line);
	piece->map = get_piecemap(piece->x, piece->y);
	return (piece);
}

char	**get_piecemap(int x, int y)
{
	int		i;
	char	**ret;
	char	*line;

	if ((ret = init_map(x, y)) == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (ret[i] == NULL || get_next_line(0, &line) == -1)
		{
			del_map(ret);
			return (NULL);
		}
		ft_strcpy(ret[i], line);
		i++;
	}
	return (ret);
}

int		is_empty(char **map, int index, char d)
{
	int	i;

	i = 0;
	while (d == 'y' && map[index][i] != '\0' && map[index][i] != '*')
		i++;
	if (d == 'y' && map[index][i] == '\0')
		return (1);
	else if (d == 'y')
		return (0);
	while (map[i] != NULL && map[i][index] != '*')
		i++;
	if (map[i] == NULL)
		return (1);
	return (0);
}
