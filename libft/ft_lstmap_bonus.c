/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:48:21 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/05 22:13:42 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*amp;

	new = NULL;
	amp = NULL;
	tmp = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (tmp)
	{
		amp = ft_lstnew(f(tmp->content));
		if (!amp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, amp);
		tmp = tmp->next;
	}
	return (new);
}
