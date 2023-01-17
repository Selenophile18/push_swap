/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:08:51 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/18 00:47:37 by hhattaki         ###   ########.fr       */
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

void	find_nb(t_stack **a, int pos)
{
	t_stack	*iter;
	
	iter = a;
	if (pos <= (*a)->size)
	{
		while (pos)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (pos < (*a)->size)
		{
			rev_rotate_a(a);
			pos++;
		}
	}
	return (iter);
}

void	a_to_b(int *arr, t_stack **a, t_stack **b, t_num *d)
{
	int		i;
	int		j;

	while (d->start >= 0 && d->end < d->arg_num)
	{
		while ((*a)->head)
		{
			i = d->start;
			j = 0;
			ft_init(a, &d);
			while (i < d->end)
			{
				// printf("%d, %d\n", iter->content, arr[i]);
				if ((*a)->head->content == arr[i])
				{
					find_nb(a, j);
					push_b(a, b);
					// printf("[%d]\n", *(b)->content);
					if (j <= d->mid + 1)
						rotate_b(b);
					break ;
				}
				i++;
				j++;
			}
			(*a)->head = (*a)->head->next;
		}
		d->start -= d->mid;
		d->end += d->mid; 
	}
}
