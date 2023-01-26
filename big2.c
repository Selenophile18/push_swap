/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:39:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 15:36:06 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search(t_stack temp, int max)
{
	int	j;

	j = 0;
	while (temp.stack)
	{
		if (temp.stack->content == max)
			break ;
		j++;
		temp.stack = temp.stack->next;
	}
	if (!temp.stack)
		return (-1);
	return (j);
}

int	to_push(t_stack *b, t_stack *a, int *arr, int len)
{
	int		found;
	int		r;
	t_list	*temp;

	found = search(*b, arr[len]);
	if (found == -1)
		return (-1);
	temp = b->head;
	r = 0;
	if (found <= b->size / 2)
	{
		while (b->head->content != arr[len])
		{
			if (len > 0 && b->head->content == arr[len - 1])
			{
				push(b, a, 1);
				r = 1;
			}
			if (b->head->content == arr[len])
				break ;
			rotate_b(b);
		}
	}
	else
	{
		while (b->head->content != arr[len])
		{
			if (len > 0 && b->head->content == arr[len - 1])
			{
				push(b, a, 1);
				r = 1;
			}
			if (b->head->content == arr[len])
				break ;
			rev_rotate(b, 1);
		}
	}
	push(b, a, 1);
	if (r == 1)
		swap(a, 0);
	return (r);
}

void	upkid(t_stack *b, t_stack *a)
{
	int	min;

	min = b->stack->content;
	while (b->stack)
	{
		if (b->stack->content < min)
			min = b->stack->content;
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	while (b->head->content != min)
	{
		rotate_b(b);
	}
	if (b->head->content == min)
	{
		push(b, a, 'b');
		rotate_a(a);
	}
}

void	b_to_a(int *arr, t_stack *a, t_stack *b, t_num *d)
{
	int		len;
	t_stack	temp;

	temp = *b;
	len = d->arg_num - 1;
	while (b->size > 0 && len >= 0)
	{
		to_push(b, a, arr, len);
		len--;
	}
	while (b->head)
		upkid(b, a);
}
