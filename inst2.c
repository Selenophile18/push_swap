/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:08 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 19:23:23 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	to_rr(t_stack *a, t_stack *b)
{
	to_rotate(a);
	to_rotate(b);
}

void	to_ss(t_stack *a, t_stack *b)
{
	to_swap(a);
	to_swap(b);
}

void	to_rrr(t_stack *a, t_stack *b)
{
	to_rev_rotate(a);
	to_rev_rotate(b);
}