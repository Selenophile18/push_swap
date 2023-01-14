/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/14 22:25:20 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*iter;
	t_list	*stack_b;
	int		*arr;
	int		i;
	t_num	d;

	stack_a = get_arg(ac, av, &d);
	stack_b = ft_calloc(1, sizeof(t_list *));
	// push_b(&stack_a, &stack_b);
	iter = stack_a;
	arr = ref_arr(stack_a, d);
	i = 0;
	while (i < d.arg_num)
	{
		printf("[%d]\n", arr[i]);
		i++;
	}
	// while (iter)
	// {
	// 	printf("[%d]\n", iter->content);
	// 	printf("[%p]\n", iter->next);
	// 	iter = iter->next;
	// }
	// if (d.arg_num < 3)
	// 	get_sorted_three(iter);
	// ft_init(&d);
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// printf("[%d]\n", is_sorted(stack_a));
}
