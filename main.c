/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/20 02:01:46 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	b;
	int		*arr;
	t_num	d;

	a = get_arg(ac, av);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	ft_init(&a, &d);
	arr = ref_arr(a, d);
	a_to_b(arr, &a, &b, &d);
}
