/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:41:28 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/30 18:38:57 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

char	**init_map(int x, int y, char flag)
{
	char	**ret;
	int		i;

	if (x <= 0 || y <= 0
			|| (ret = (char **)malloc((y + 1) * sizeof(char *))) == NULL)
		return (NULL);
	ft_bzero(ret, sizeof(char *) * (y + 1));
	i = 0;
	while (i < y)
	{
		if ((ret[i] = ft_strnew(x)) == NULL)
			break ;
		i++;
	}
	if (i != y)
		del_map(ret);
	if (flag == 'b' && cp_board(x, y, ret) == NULL)
	{
		del_map(ret);
		return (NULL);
	}
	return (ret);
}

void	del_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
