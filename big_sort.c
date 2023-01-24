/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 00:50:38 by hhattaki         ###   ########.fr       */
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
			rotate(a, 'a');
	}
	else
	{
		while ((*a)->head->content != nb)
			rev_rotate(a, 'a');
	}
	push(a, b, 'b');
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

void upkid(t_stack *b, t_stack *a)
{
	int min;
	min = b->stack->content;
	while(b->stack)
	{
		if (b->stack->content < min)
			min = b->stack->content;
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	while (b->head->content != min)
	{	
		rotate(&b, 'b');
	}
	if (b->head->content == min)
	{
		push(&b, a, 'b');
		rotate(&a, 'a');
	}
		
	
}
void	check_b(t_stack *a, t_stack *b)
{
	while(b->head)
	{
		upkid(b,a);
	}
	// temp = b->head;
	// while (b->size > 0)
	// {
	// 	temp = *b;
	// 	len = -1;
	// 	while (++len < d->arg_num)
	// 	{
	// 		while (temp.head)
	// 		{
	// 		if (temp.head->content == arr[len])
	// 		{
	// 			if (search(*b, arr[len]) <= b->size / 2)
	// 			{
	// 				while (b->head->content != arr[len])
	// 				rotate(&a, 'a');
	// 			}
	// 			else
	// 			{
	// 				while (b->head->content != arr[len])
	// 					rev_rotate(&b, 'b');
	// 				push(&b, a, 'b');
	// 			}
	// 			temp.head = b->head;
	// 			break;
	// 		}
	// 		temp.head = temp.head->next;
	// 		}
	// 	}
	// }
}

void	a_to_b(int *arr, t_stack **a, t_stack *b, t_num *d)
{
	int		t;
	t_stack	*temp;

	temp = (*a);
	while ((*a)->size)
	{
		temp->stack = (*a)->head;
		while (temp->stack)
		{
			t = iter(temp->stack->content, *d, arr);
			if (t == -1)
				temp->stack = temp->stack->next;
			else
			{
				find_nb(a, b, temp->stack->content);
				if (t < d->m)
					rotate(&b, 'b');
				temp->stack = (*a)->head;
			}
		}
		d->start -= d->offset;
		d->end += d->offset;
	}
	b_to_a(arr, *a, b, d);
}
