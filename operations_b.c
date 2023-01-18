/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:33:57 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/18 23:35:08 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	int		temp;
	t_list	*iter;

	if (b->size < 2)
		return ;
	temp = b->head->content;
	iter = b->head->next;
	b->head->content = iter->content;
	iter->content = temp;
	ft_putendl_fd("sb", 1);
}

void	rotate_b(t_stack **b)
{
	t_list	*temp;

	if ((*b)->size < 2)
		return ;
	temp = (*b)->head;
	(*b)->head = (*b)->head->next;
	(*b)->stack = (*b)->head;
	while ((*b)->stack->next)
		(*b)->stack = (*b)->stack->next;
	(*b)->stack->next = temp;
	temp->next = NULL;
	(*b)->stack = (*b)->head;
	ft_putendl_fd("rb", 1);
}

void	push_a(t_stack **b, t_stack **a)
{
	t_list	*temp;

	temp = (*b)->head;
	if (!(*b)->head)
		return ;
	(*b)->head = (*b)->head->next;
	(*b)->stack = (*b)->head;
	temp->next = (*a)->head;
	(*a)->head = temp;
	ft_putendl_fd("pa", 1);
	(*b)->size -= 1;
	(*b)->size += 1;
}

void	rev_rotate_b(t_stack **b)
{
	t_list	*temp;

	if ((*b)->size < 2)
		return ;
	temp = (*b)->head;
	while ((*b)->stack->next)
	{
		temp = (*b)->stack;
		(*b)->stack = (*b)->stack->next;
	}
	temp->next = NULL;
	(*b)->stack->next = (*b)->head;
	ft_putendl_fd("rrb", 1);
	(*b)->head = (*b)->stack;
}