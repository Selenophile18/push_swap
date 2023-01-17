/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/18 00:44:20 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	t_num	d;

	a = get_arg(ac, av);
	b = 0;
	ft_init(a, &d);
	arr = ref_arr(a, d);
	a_to_b(arr, &a, &b, &d);
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
