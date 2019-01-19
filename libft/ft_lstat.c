/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:43:32 by mnishimo          #+#    #+#             */
/*   Updated: 2018/11/28 22:54:54 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstat(t_list *alst, unsigned int nbr)
{
	unsigned int	i;
	t_list			*ptr;

	i = 0;
	if (alst == NULL)
		return (NULL);
	ptr = alst;
	while (ptr->next != NULL && i < nbr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == nbr)
		return (ptr);
	return (NULL);
}
