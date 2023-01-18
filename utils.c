/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:58:41 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/18 18:53:05 by hhattaki         ###   ########.fr       */
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
	if (d->arg_num <= 17)
		d->nb = 4;
	else if (d->arg_num <= 150)
		d->nb = 8;
	else if (d->arg_num > 150)
		d->nb = 20;
	d->mid = (*a)->size / 2;
	d->offset = d->arg_num / d->nb;
	d->start = d->mid - d->offset;	
	d->end = d->mid + d->offset;
}