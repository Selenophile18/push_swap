/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:33:57 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/14 20:42:31 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list *lst)
{
	int		temp;
	t_list	*iter;

	temp = lst->content;
	iter = lst;
	iter = iter->next;
	lst->content = iter->content;
	lst = lst->next;
	lst->content = temp;
	ft_putendl_fd("sb", 1);
}

t_list	*rotate_b(t_list *lst)
{
	t_list	*temp;
	t_list	*iter;

	temp = lst;
	iter = lst;
	lst = lst->next;
	while (iter->next)
		iter = iter->next;
	iter->next = temp;
	temp->next = NULL;
	ft_putendl_fd("rb", 1);
	return (lst);
}

void	push_a(t_list **b, t_list **a)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_putendl_fd("pa", 1);
}

t_list	*rev_rotate_b(t_list *lst)
{
	t_list	*temp;
	t_list	*iter;

	iter = lst;
	temp = lst;
	while (iter->next)
	{
		temp = iter;
		iter = iter->next;
	}
	temp->next = NULL;
	iter->next = lst;
	lst = iter;
	ft_putendl_fd("rrb", 1);
	return (lst);
}
