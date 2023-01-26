/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:48 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_nb(t_stack *a, t_stack *b, int nb)
{
	int		j;
	t_list	*tmp;

	tmp = a->head;
	j = 0;
	while (tmp->content != nb)
	{
		j++;
		tmp = tmp->next;
	}
	if (j <= a->size / 2)
	{
		while (a->head->content != nb)
			rotate_a(a);
	}
	else
	{
		while (a->head->content != nb)
			rev_rotate(a, 0);
	}
	push(a, b, 0);
}

int	iter(int tmp, t_num d, int *arr)
{
	int	mv;

	if (d.start < 0)
		d.start = 0;
	mv = d.start;
	while (mv < d.end)
	{
		if (tmp == arr[mv])
			return (mv);
		mv++;
	}
	return (-1);
}

void	a_to_b(int *arr, t_stack *a, t_stack *b, t_num *d)
{
	int		t;
	t_stack	*temp;

	temp = a;
	while (a->size)
	{
		temp->stack = a->head;
		while (temp->stack)
		{
			t = iter(temp->stack->content, *d, arr);
			if (t == -1)
				temp->stack = temp->stack->next;
			else
			{
				find_nb(a, b, temp->stack->content);
				if (t < d->m)
					rotate_b(b);
				temp->stack = a->head;
			}
		}
		d->start -= d->offset;
		d->end += d->offset;
	}
	b_to_a(arr, a, b, d);
}
