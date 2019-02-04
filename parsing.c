/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/30 18:49:15 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

char	**get_game(t_game *game)
{
	char	*i;
	char	*line;
	char	**ret;

	game->toggle = 0;
	if (skip_till("$$$ exec p", &line, 10) < 1)
		return (NULL);
	game->p = get_playernbr(line);
	free(line);
	if (skip_till("Plateau ", &line, 8) < 1)
		return (NULL);
	if (line[8] == '\0' || (i = ft_strchr(line + 8, ' ')) == NULL
		|| (game->y = ft_atoi(line + 8)) <= 0
		|| (game->x = ft_atoi(i)) <= 0)
	{
		free(line);
		return (NULL);
	}
	free(line);
	if ((ret = init_map(game->x, game->y, 'b')) == NULL)
		return (NULL);
	return (ret);
}

char	get_playernbr(char *line)
{
	char	*ptr;
	int		p;

	if (line == NULL || ft_strlen(line) < 11)
		return ('o');
	ptr = line;
	p = ft_atoi(line + 10);
	while (*ptr != '\0')
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
			break ;
		free(*line);
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
		if (ft_strlen(line) < 5)
		{
			free(line);
			return (NULL);
		}
		ft_strncpy(board[lc], line + 4, x);
		free(line);
		if (lc != y - 1 && get_next_line(0, &line) <= 0)
			return (NULL);
		lc++;
	}
	return (board);
}
