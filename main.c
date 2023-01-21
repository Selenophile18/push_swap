/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/21 23:10:01 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	b;
	int		*arr;
	t_num	d;

	if (ac == 1)
		exit(0);
	a = get_arg(ac, av);
	ft_init(&a, &d);
	if (d.arg_num < 4)
		get_sorted_three(a);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	arr = ref_arr(a, d);
	a_to_b(arr, &a, &b, &d);
	// b_to_a(arr, a, &b, &d);
	// system("leaks push_swap");
}
