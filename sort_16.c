/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:41:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 19:25:12 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		push(b, a, 'a');
		if (a->head->next && a->head->content > a->head->next->content)
			swap(a, 'a');
	}
}

int	find(t_stack *a, t_stack *b, int nb)
{
	t_list	*temp;
	int		j;

	temp = a->head;
	j = 0;
	while (temp->content != nb)
	{
		j++;
		temp = temp->next;
	}
	if (!temp)
		return (-1);
	if (j <= a->size / 2)
	{
		while (a->head->content != nb)
			rotate(a, 'a');
	}
	else
	{
		while (a->head->content != nb)
			rev_rotate(a, 'a');
	}
	push(a, b, 'b');
	return (0);
}

void	get_sorted(t_stack *a, t_stack *b, int *arr, t_num *d)
{
	int		i;
	int		r;
	t_list	*temp;

	i = -1;
	while (a->size > 3)
	{
		temp = a->head;
		while (temp && ++i < d->arg_num)
		{
			r = find(a, b, arr[i]);
			if (r == -1)
				temp = temp->next;
			else
			{
				if (b->head->next && b->head->next->content < b->head->content)
					swap(b, 'b');
				temp = a->head;
			}
			if (a->size == 3)
				break ;
		}
	}
	get_sorted_three(a);
	back_to_a(a, b);
}
