/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:39:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 19:19:50 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

int	to_rotate(t_stack *b, t_stack *a, int *arr, int len)
{
	int	r;

	r = 0;
	while (b->head->content != arr[len])
	{
		if (len > 0 && b->head->content == arr[len - 1])
		{
			push(b, a, 'a');
			r = 1;
		}
		if (b->head->content == arr[len])
			break ;
		rotate(b, 'b');
	}
	push(b, a, 'a');
	return (r);
}

int	to_rev_rotate(t_stack *b, t_stack *a, int *arr, int len)
{
	int	r;

	r = 0;
	while (b->head->content != arr[len])
	{
		if (len > 0 && b->head->content == arr[len - 1])
		{
			push(b, a, 'a');
			r = 1;
		}
		if (b->head->content == arr[len])
			break ;
		rev_rotate(b, 'b');
	}
	push(b, a, 'a');
	return (r);
}

void	to_push(t_stack *b, t_stack *a, int *arr, int len)
{
	int		found;
	int		r;
	t_list	*temp;

	found = search(*b, arr[len]);
	if (found == -1)
		return ;
	temp = b->head;
	r = 0;
	if (found <= b->size / 2)
		r = to_rotate(b, a, arr, len);
	else
		r = to_rev_rotate(b, a, arr, len);
	if (r == 1)
		swap(a, 'a');
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
	check_b(a, b);
}
