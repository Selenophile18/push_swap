/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:21:26 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/24 00:03:49 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	less_arg(t_stack *stack)
{
	t_list	*iter;
	int		a;
	int		b;

	if (!stack->head->next)
		exit(0);
	iter = stack->head->next;
	a = stack->head->content;
	b = iter->content;
	if (a > b)
		swap(stack, 'a');
	exit(0);
}

void	get_sorted_three(t_stack *stack)
{
	t_list	*t1;
	t_list	*t2;
	t_list	*t3;

	t1 = stack->head;
	t2 = stack->head->next;
	if (!t2 || !t2->next)
		less_arg(stack);
	t3 = t2->next;
	if ((t2->content > t3->content && t3->content > t1->content)
		|| (t3->content > t1->content && t1->content > t2->content)
		|| (t1->content > t2->content && t2->content > t3->content))
		swap(stack, 'a');
	if (t1->content < t2->content && t2->content > t3->content)
		rev_rotate(&stack, 'a');
	if (t1->content > t2->content && t1->content > t3->content)
		rotate(&stack, 'a');
	if (is_sorted(stack))
		exit(0);
}
