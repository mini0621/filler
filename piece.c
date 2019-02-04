/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:13:46 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/30 19:52:42 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_piece	*get_piece(t_piece *piece)
{
	char	*line;
	char	*i;

	if (skip_till("Piece ", &line, 6) < 1)
		return (NULL);
	i = line + 6;
	if (line[6] == '\0' || (i = ft_strchr(i, ' ')) == NULL || *i == '\0')
	{
		free(line);
		return (NULL);
	}
	if ((piece->y = ft_atoi(line + 6)) <= 0
		|| (piece->x = ft_atoi(i)) <= 0)
	{
		free(line);
		return (NULL);
	}
	free(line);
	if ((piece->map = get_piecemap(piece->x, piece->y)) == NULL)
		return (NULL);
	return (piece);
}

char	**get_piecemap(int x, int y)
{
	int		i;
	char	**ret;
	char	*line;

	if ((ret = init_map(x, y, 'p')) == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (ret[i] == NULL || get_next_line(0, &line) < 1)
		{
			del_map(ret);
			return (NULL);
		}
		if (ft_strlen(line) != (unsigned int)x)
		{
			del_map(ret);
			free(line);
			return (NULL);
		}
		ft_strcpy(ret[i], line);
		free(line);
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

t_coord	*start_piece(t_coord *dir, t_coord *coord, t_piece *piece)
{
	dir->x *= -1;
	dir->y *= -1;
	coord = start_coord(dir, coord, piece->x, piece->y);
	dir->x *= -1;
	dir->y *= -1;
	return (coord);
}
