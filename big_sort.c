/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/20 02:01:34 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_arr(int *arr, t_num d)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < d.arg_num)
	{
		j = i + 1;
		while (j < d.arg_num)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*ref_arr(t_stack *stack, t_num d)
{
	int		*arr;
	t_list	*iter;
	int		i;

	iter = stack->head;
	i = 0;
	arr = ft_calloc(d.arg_num, sizeof(int));
	while (iter && i < d.arg_num)
	{
		arr[i] = iter->content;
		i++;
		iter = iter->next;
	}
	sort_arr(arr, d);
	return (arr);
}

void	find_nb(t_stack **a, t_stack *b, int nb)
{
	int		j;
	int		mid;
	t_list	*tmp;

	tmp = (*a)->head;
	j = 0;
	mid = (*a)->size / 2;
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
			rev_rotate_a(a);
	}
	push_b(a, b);
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

void	check_a(t_stack **a, t_stack *b, int *arr, t_num d)
{
	int	i;

	while (ft_lstsize(b->head) < d.arg_num)
	{
		i = 0;
		while (i < d.arg_num && arr[i] != (*a)->head->content)
				i++;
		find_nb(a, b, (*a)->head->content);
		if (i < d.m)
			rotate_b(&b);	
	}
}

void	a_to_b(int *arr, t_stack **a, t_stack *b, t_num *d)
{
	int		i;
	int		j;
	int		t;
	t_stack *temp;

	temp = (*a);
	while (d->start >= 0 || d->end <= d->arg_num)
	{
		j = 0;
		temp->stack = (*a)->head;
		while (temp->stack)
		{
			i = d->start;
			t = iter(temp->stack->content, a, b, *d, arr);
			if (!t)
				temp->stack = temp->stack->next;
			else
				temp->stack = (*a)->head;
			j++;
		}
		d->start -= d->offset;
		d->end += d->offset;
	}
	check_a(a, b, arr, *d);
}
