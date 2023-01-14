/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/14 22:46:24 by hhattaki         ###   ########.fr       */
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
}	t_num;

/*---------operations---------*/
void	swap_a(t_list *lst);
t_list	*rotate_a(t_list *lst);
t_list	*rev_rotate_a(t_list *lst);
void	push_b(t_list **a, t_list **b, t_num *d);
void	swap_b(t_list *lst);
t_list	*rotate_b(t_list *lst);
t_list	*rev_rotate_b(t_list *lst);
void	push_a(t_list **b, t_list **a);
/*-------error-handling-------*/
void	max_min(char	*str);
char	*str_isdigit(char	*s);
void	ft_check_duplicate(t_list *stack);
void	final_check(int ac, char	**av);
/*--------get-arguments-------*/
t_list	*get_int(int ac, char **av, t_list	*node);
t_list	*get_arg(int ac, char **av, t_num *d);
/*------------utils-----------*/
int		is_sorted(t_list *stack);
void	ft_init(t_num *d);
/*---------sorting------------*/
void	get_sorted_three(t_list	*stack);
int		*ref_arr(t_list	*stack, t_num d);

#endif