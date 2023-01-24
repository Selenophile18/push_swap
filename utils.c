/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:58:41 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/24 20:53:44 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*temp;
	t_list	*iter;

	iter = stack->head;
	while (iter)
	{
		temp = iter->next;
		while (temp)
		{
			if (iter->content > temp->content)
				return (0);
			temp = temp->next;
		}
		iter = iter->next;
	}
	return (1);
}

void	ft_init(t_stack **a, t_num *d)
{
	d->arg_num = (*a)->size;
	if (d->arg_num <= 150)
		d->nb = 8;
	else if (d->arg_num > 150)
		d->nb = 14;
	d->mid = (*a)->size / 2;
	d->m = d->mid;
	d->offset = d->arg_num / d->nb;
	d->start = d->mid - d->offset;
	d->end = d->mid + d->offset;
}

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
