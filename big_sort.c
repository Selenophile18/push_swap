/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/18 23:37:14 by hhattaki         ###   ########.fr       */
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

void	find_nb(t_stack **a, int pos, int nb)
{
	printf("size = %d\n", (*a)->size);
	if (pos <= (*a)->size / 2)
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

	temp = (*a); 
	// katwse3li l array
	while (d->start >= 0 && d->end < d->arg_num)
	{
		// kador 3la stack
		j = 0;
		while (temp->head)
		{
			i = d->start;
			// kador 3la array
			while (i < d->end)
			{
				printf("%d, %d j: %d\n", (*a)->stack->content, arr[i], j);
				t = 0;
				// fash kanlqa f stack 3la shnu 3ndi f array
				if (temp->stack->content == arr[i])
				{
					t = 1;
					find_nb(a, j, temp->stack->content);
					// printf("j = %d\n", j);
					push_b(a, b);
					if (i < d->mid)
						rotate_b(&b);
					// printf("here\n");
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
		d->start -= d->mid;
		d->end += d->mid; 
	}
}
