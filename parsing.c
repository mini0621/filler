/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:35:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/19 19:52:28 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

char	*get_game(t_game *game)
{
	char	*i;
	char	*line;

	if (game == NULL || get_next_line(0, &line) < 1)
		return (NULL);
	while (ft_strncmp("$$$", line, 3) != 0)
	{
		free(line);
		if (get_next_line(0, &line) < 1)
			return (NULL);
	}
	game->p = get_playernbr(line);
	while (ft_strncmp(line, "Plateau", 7) != 0)
	{
		free(line);
		if (get_next_line(0, &line) < 1)
			return (NULL);
	}
	i = line + 8;
	game->y = ft_atoi(i);
	while (*i != ' ')
		i++;
	game->x = ft_atoi(i + 1);
	free(line);
	return (init_board(game));
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

char	*init_board(t_game *game)
{
	char	*ret;

	if (game == NULL || game->x <= 0 || game->y <= 0
			|| (ret = ft_strnew(game->x * game->y)) == NULL)
		return (NULL);
	if (cp_board(game->x, game->y, ret) == NULL )
		return (NULL);
	return (ret);
}

char	*cp_board(int x, int y, char *board)
{
	int		lc;
	char	*line;
	
	lc = 0;
	while (lc <= y)
	{
		if (get_next_line(0, &line) <= 0)
			return (NULL);
		if (lc != 0)
			ft_strncat(board, line + 4, x);
		free(line);
		lc++;
	}
	return (board);
}
