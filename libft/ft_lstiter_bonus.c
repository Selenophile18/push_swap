/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:48:01 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/05 22:09:24 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*tmp;

	tmp = lst;
	if (!lst || !f)
		return ;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
