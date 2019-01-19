/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:24:46 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/06 15:00:24 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelof(t_list **alst, void *content,
		int (*cmp)(void *, void *))
{
	t_list	*pre;
	t_list	*cur;

	cur = *alst;
	while (cur != NULL)
	{
		if ((*cmp)(cur->content, content) == 0)
		{
			if (cur == *alst)
				*alst = cur->next;
			else
				pre->next = cur->next;
			free(cur->content);
			free(cur);
			cur = NULL;
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}
