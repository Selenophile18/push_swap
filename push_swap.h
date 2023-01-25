/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/25 20:53:53 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<limits.h>
# include"./libft/libft.h"
# include<stdio.h>
# include<string.h>

typedef struct s_num
{
	int	arg_num;
	int	mid;
	int	nb;
	int	offset;
	int	start;
	int	end;
	int	m;
	int	n;
}	t_num;

typedef	struct s_stack
{
	t_list	*head;
	t_list	*stack;
	int		size;
}	t_stack;


/*---------operations---------*/
void	swap(t_stack *a, int c);
void	rotate(t_stack *a, int c);
void	rev_rotate(t_stack *a, int c);
void	push(t_stack *a, t_stack *b, int c);
/*-------error-handling-------*/
void	max_min(char	*str);
char	*str_isdigit(char	*s);
void	ft_check_duplicate(t_stack a);
void	final_check(char	*all);
/*--------get-arguments-------*/
t_stack	*get_int(int ac, char **av, t_stack	*node);
void	get_arg(int ac, char **av, t_stack *a);
/*------------utils-----------*/
int		is_sorted(t_stack *stack);
void	ft_init(t_stack *a, t_num *d);
void	ft_free(char	**av);
/*---------sorting------------*/
int		search(t_stack temp, int max);
void	get_sorted_three(t_stack	*stack);
int		*ref_arr(t_stack	*stack, t_num d);
void	a_to_b(int *arr, t_stack *a, t_stack *b, t_num *d);
void	b_to_a(int *arr, t_stack *a, t_stack *b, t_num *d);
void	get_sorted(t_stack *a, t_stack *b, int *arr, t_num *d);
void	check_b(t_stack *a, t_stack *b);

#endif