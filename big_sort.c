/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/23 17:30:28 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	find_nb(t_stack **a, t_stack *b, int nb)
{
	int		j;
	t_list	*tmp;

	tmp = (*a)->head;
	j = 0;
	while (tmp->content != nb)
	{
		j++;
		tmp = tmp->next;
	}
	if (j <= (*a)->size / 2)
	{
		while ((*a)->head->content != nb)
			rotate_a(a);
	}
	else
	{
		while ((*a)->head->content != nb)
			rev_rotate(a, 0);
	}
	push(a, b, 0);
}	

int	iter(int tmp, t_stack **a, t_stack *b, t_num d, int *arr)
{
	while (d.start < d.end)
	{
		if (tmp == arr[d.start])
		{
			find_nb(a, b, tmp);
			if (d.start < d.m)
				rotate_b(&b);
			return (1);
		}
		d.start++;
	}
	return (0);
}

void	a_to_b(int *arr, t_stack **a, t_stack *b, t_num *d)
{
	int			i;
	int			t;
	t_stack 	*temp;

	temp = (*a);
	while ((*a)->size)
	{
		temp->stack = (*a)->head;
		while (temp->stack)
		{
			i = d->start;
			t = iter(temp->stack->content, a, b, *d, arr);
			if (!t)
				temp->stack = temp->stack->next;
			else
				temp->stack = (*a)->head;
		}
		d->start -= d->offset;
		d->end += d->offset;
	}
}