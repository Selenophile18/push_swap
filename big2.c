/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:39:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/21 17:43:21 by hhattaki         ###   ########.fr       */
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
	return (j);
}

int	det_found(t_stack temp, int *arr, t_num d, int len)
{
	int	max;
	int	bfr;

	max = search(temp, arr[len]);
	bfr = search(temp, arr[len - 1]);
	if ((max <= d.m && max > bfr) || (max > d.m && max < bfr))
		return (1);
	return(0);
}

void	to_push(int nb, t_stack *b, t_stack *a)
{
	int	found;

	found = search(*b, nb);
	if (found <= b->size / 2)
	{
		while (b->head->content != nb)
			rotate_b(&b);
	}
	else
	{
		while (b->head->content != nb)
			rev_rotate_b(&b);
	}
	push_a(&b, a);
}

void	b_to_a(int *arr, t_stack *a, t_stack *b, t_num *d)
{
	int		m;
	int		len;
	t_stack	temp;

	temp = *b;
	len = d->arg_num - 1;
	while ((len - 1) >= 0)
	{
		m = det_found(temp, arr, *d, len);
		if (m)
			to_push(arr[len - 1], b, a);
		to_push(arr[len], b, a);
		if (m)
		{
			swap_a(a);
			len--;
		}
		len--;
	}
	while(ft_lstsize(a->head) < d->arg_num)
		to_push(b->head->content, b, a);
}