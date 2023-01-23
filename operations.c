/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:15:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/24 00:03:25 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, int c)
{
	int		temp;
	t_list	*iter;

	if (a->size < 2)
		return ;
	temp = a->head->content;
	iter = a->head->next;
	a->head->content = iter->content;
	iter->content = temp;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
}

void	rotate(t_stack **a, int c)
{
	t_list	*temp;

	if ((*a)->size < 2)
		return ;
	temp = (*a)->head;
	(*a)->head = (*a)->head->next;
	(*a)->stack = (*a)->head;
	while ((*a)->stack->next)
		(*a)->stack = (*a)->stack->next;
	(*a)->stack->next = temp;
	temp->next = NULL;
	(*a)->stack = (*a)->head;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
}

void	push(t_stack **a, t_stack *b, int c)
{
	if (!(*a)->head)
		return ;
	(*a)->stack = (*a)->head;
	(*a)->head = (*a)->head->next;
	(*a)->stack->next = b->head;
	b->head = (*a)->stack;
	(*a)->stack = (*a)->head;
	if (c == 'b')
		ft_putendl_fd("pb", 1);
	else if (c == 'a')
		ft_putendl_fd("pa", 1);
	(*a)->size -= 1;
	b->size += 1;
}

void	rev_rotate(t_stack **a, int c)
{
	t_list	*temp;

	if ((*a)->size < 2)
		return ;
	temp = (*a)->head;
	while ((*a)->stack->next)
	{
		temp = (*a)->stack;
		(*a)->stack = (*a)->stack->next;
	}
	temp->next = NULL;
	(*a)->stack->next = (*a)->head;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	(*a)->head = (*a)->stack;
}
