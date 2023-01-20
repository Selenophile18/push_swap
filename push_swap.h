/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/19 23:21:02 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<limits.h>
# include"./libft/libft.h"
# include<stdio.h>

typedef struct s_num
{
	int	arg_num;
	int	mid;
	int	nb;
	int	offset;
	int	start;
	int	end;
	int	m;
}	t_num;

typedef	struct s_stack
{
	t_list	*head;
	t_list	*stack;
	int		size;
}	t_stack;


/*---------operations---------*/
void	swap_a(t_stack *a);
void	rotate_a(t_stack **a);
void	rev_rotate_a(t_stack **a);
void	push_b(t_stack **a, t_stack *b);
void	swap_b(t_stack *b);
void	rotate_b(t_stack **b);
void	rev_rotate_b(t_stack **b);
void	push_a(t_stack **b, t_stack **a);
/*-------error-handling-------*/
void	max_min(char	*str);
char	*str_isdigit(char	*s);
void	ft_check_duplicate(char	**arg);
void	final_check(char	*all);
/*--------get-arguments-------*/
t_stack	*get_int(int ac, char **av, t_stack	*node);
t_stack	*get_arg(int ac, char **av);
/*------------utils-----------*/
int		is_sorted(t_stack *stack);
void	ft_init(t_stack **a, t_num *d);
/*---------sorting------------*/
void	get_sorted_three(t_stack	*stack);
int		*ref_arr(t_stack	*stack, t_num d);
void	a_to_b(int *arr, t_stack **a, t_stack *b, t_num *d);

#endif