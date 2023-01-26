/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:14:58 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 19:20:53 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	to_swap(t_stack *a)
{
	int		temp;
	t_list	*iter;

	if (a->size < 2)
		return ;
	temp = a->head->content;
	iter = a->head->next;
	a->head->content = iter->content;
	iter->content = temp;
}

void	to_rotate(t_stack *a)
{
	t_list	*temp;

	if (a->size < 2)
		return ;
	temp = a->head;
	a->head = a->head->next;
	a->stack = a->head;
	while (a->stack->next)
		a->stack = a->stack->next;
	a->stack->next = temp;
	temp->next = NULL;
	a->stack = a->head;
}

void	to_push(t_stack *a, t_stack *b)
{
	if (!a->head)
		return ;
	a->stack = a->head;
	a->head = a->head->next;
	a->stack->next = b->head;
	b->head = a->stack;
	a->stack = a->head;
	a->size -= 1;
	b->size += 1;
}

void	to_rev_rotate(t_stack *a)
{
	t_list	*temp;

	if (a->size < 2)
		return ;
	temp = a->head;
	while (a->stack->next)
	{
		temp = a->stack;
		a->stack = a->stack->next;
	}
	temp->next = NULL;
	a->stack->next = a->head;
	a->head = a->stack;
}
