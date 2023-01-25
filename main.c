/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 20:46:57 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int		*arr;
	t_num	d;

	if (d.arg_num < 4)
		return(get_sorted_three(a));
	ft_init(a, &d);
	arr = ref_arr(a, d);
	if (d.arg_num < 17)
		return(get_sorted(a, b, arr, &d));
	else
		a_to_b(arr, a, b, &d);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		exit(0);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	a.head = 0;
	a.stack = 0;
	a.size = 0;
	get_arg(ac, av, &a);
	if (is_sorted(&a))
		exit (0);
	push_swap(&a, &b);
}
