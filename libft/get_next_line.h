/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:24:02 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/10 12:17:13 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 5

typedef struct	s_fd
{
	int		fd;
	char	*remain;
}				t_fd;

int				get_next_line(const int fd, char **line);
int				cmpfd(void *fd1, void *fd);
t_list			*initbuff(int fd, t_list **lst, char **buff,
		int *readsize);
t_list			*initfd(t_list **lst, int fd);
int				findline(const int fd, char **buff, t_list *fdlst,
		char **line);

#endif
