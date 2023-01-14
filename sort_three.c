/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:21:26 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/14 16:58:38 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	less_arg(t_list *stack)
{
	t_list	*iter;
	int		a;
	int		b;

	if (!stack->next)
		exit(0);
	iter = stack->next;
	a = stack->content;
	b = iter->content;
	if (a > b)
		swap_a(stack);
	exit(0);
}

void	get_sorted_three(t_list	*stack)
{
	t_list	*t1;
	t_list	*t2;
	t_list	*t3;
	t_list	*iter;

	t1 = stack;
	t2 = stack->next;
	if (!t2 || !t2->next)
		less_arg(stack);
	t3 = t2->next;
	iter = stack;
	if ((t2->content > t3->content && t3->content > t1->content)
		|| (t3->content > t2->content && t2->content < t1->content)
		|| (t1->content > t2->content && t2->content > t3->content))
		swap_a(stack);
	if (is_sorted(stack))
		exit(0);
	if (t1->content < t2->content && t2->content > t3->content)
		stack = rev_rotate_a(stack);
	if (is_sorted(stack))
		exit(0);
	if (t1->content > t2->content && t1->content > t3->content)
		stack = rotate_a(stack);
}
