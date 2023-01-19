/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/19 17:55:23 by hhattaki         ###   ########.fr       */
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

void	find_nb(t_stack **a, int nb)
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
	// printf("size = %d\n", (*a)->size);
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
}

void	a_to_b(int *arr, t_stack **a, t_stack *b, t_num *d)
{
	int		i;
	int		j;
	int		t;
	t_stack *temp;

	// katwse3li l array
	temp = (*a);
	i = 0;
	while (d->start >= 0 && d->end <= d->arg_num)
	{
		// kador 3la stack
		j = 0;
		// printf("here\n");
		temp->stack = (*a)->head;
		while (temp->stack)
		{
			i = d->start;
			// kador 3la array
			while (i < d->end)
			{
				printf("%d, %d start: %d\n", (*a)->stack->content, arr[i], d->start);
				t = 0;
				// fash kanlqa f stack 3la shnu 3ndi f array
				if (temp->stack->content == arr[i])
				{
					t = 1;
					find_nb(a, temp->stack->content);
					push_b(a, b);
					if (i < d->mid)
						rotate_b(&b);
					break ;
				}
				i++;
			}
			// katshufli wash incrementit f stack
			if (!t)
				temp->stack = temp->stack->next;
			else
				temp->stack = (*a)->head;
			j++;
		}
		d->mid = (*a)->size / 2;
		d->start -= d->mid;
		d->end += d->mid; 
		// printf("here start: %d, end: %d mid: %d\n", d->start, d->end, d->mid);
	}
}
