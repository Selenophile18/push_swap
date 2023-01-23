/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:48:11 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/05 20:48:13 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!lst)
		return (NULL);
	tmp = lst;
	while (i < ft_lstsize(lst))
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
