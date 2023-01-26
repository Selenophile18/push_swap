/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 15:49:05 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*arr;
	t_num	d;

	if (ac == 1)
		exit(0);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	a.head = 0;
	a.stack = 0;
	a.size = 0;
	get_arg(ac, av, &a);
	ft_init(&a, &d);
	if (is_sorted(&a))
		exit (0);
	arr = ref_arr(&a, d);
	if (d.arg_num < 4)
		get_sorted_three(&a);
	if (d.arg_num < 17)
		get_sorted(&a, &b, arr, &d);
	else
		a_to_b(arr, &a, &b, &d);
}
