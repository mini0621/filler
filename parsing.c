/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/24 13:33:05 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

char	**get_game(t_game *game)
{
	char	*i;
	char	*line;
	char	**ret;

	if (game == NULL)
		return (NULL);
	game->toggle = 0;
	if (skip_till("$$$", &line, 3) < 1)
		return (NULL);
	game->p = get_playernbr(line);
	free(line);
	if (skip_till("Plateau", &line, 7) < 1)
		return (NULL);
	i = line + 8;
	game->y = ft_atoi(i);
	while (*i != ' ')
		i++;
	game->x = ft_atoi(i + 1);
	free(line);
	if ((ret = init_map(game->x, game->y)) == NULL)
		return (NULL);
	return (cp_board(game->x, game->y, ret));
}

char	get_playernbr(char *line)
{
	char	*ptr;
	int		p;

	ptr = line;
	p = ft_atoi(line + 10);
	while(*ptr != '\0')
	{
		if (*ptr == '/')
			line = ptr;
		ptr++;
	}
	if (ft_strncmp(line + 1, "mnishimo.filler", 15) == 0)
		return ((p == 1) ? 'o' : 'x');
	return ((p == 1) ? 'x' : 'o');
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

char	**cp_board(int x, int y, char **board)
{
	int		lc;
	char	*line;

	lc = 0;
	if (skip_till("000", &line, 3) < 1)
		return (NULL);
	while (lc < y)
	{
		ft_strncpy(board[lc], line + 4, x);
		free(line);
		if (lc != y - 1 && get_next_line(0, &line) <= 0)
			return (NULL);
		lc++;
	}
	return (board);
}
