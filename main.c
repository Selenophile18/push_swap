/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 00:51:13 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int		*arr;
	t_list *t;
	t_num	d;

	if (d.arg_num < 4)
		return(get_sorted_three(a));
	ft_init(&a, &d);
	arr = ref_arr(a, d);
	if (d.arg_num < 17)
		return(get_sorted(a, b, arr, &d));
	else
		a_to_b(arr, &a, b, &d);
	// b_to_a(arr, a, b, &d);
	t = a->head;
	// if (is_sorted(a))
	// 	printf("yay");
	// while (t)
	// {
	// 	printf("%d\n", t->content);
	// 	t = t->next;
	// }
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	b;

	if (ac == 1)
		exit(0);
	a = get_arg(ac, av);
	if (is_sorted(a))
		exit (0);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	push_swap(a, &b);
}
