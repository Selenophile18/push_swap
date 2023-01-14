/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:15:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/14 20:41:14 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *lst)
{
	int		temp;
	t_list	*iter;

	temp = lst->content;
	iter = lst;
	iter = iter->next;
	lst->content = iter->content;
	lst = lst->next;
	lst->content = temp;
	ft_putendl_fd("sa", 1);
}

t_list	*rotate_a(t_list *lst)
{
	t_list	*temp;
	t_list	*iter;

	temp = lst;
	lst = lst->next;
	iter = lst;
	while (iter->next)
		iter = iter->next;
	iter->next = temp;
	temp->next = NULL;
	ft_putendl_fd("ra", 1);
	return (lst);
}

void	push_b(t_list **a, t_list **b, t_num *d)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_putendl_fd("pb", 1);
	d->arg_num -= 1;
	
}

t_list	*rev_rotate_a(t_list *lst)
{
	t_list	*temp;
	t_list	*iter;

	temp = lst;
	iter = lst;
	while (iter->next)
	{
		temp = iter;
		iter = iter->next;
	}
	temp->next = NULL;
	iter->next = lst;
	ft_putendl_fd("rra", 1);
	return (iter);
}
