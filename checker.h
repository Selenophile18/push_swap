/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:17:14 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 20:27:18 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include"../push_swap.h"
#include"../libft/libft.h"
#include"../libft/get_next_line.h"

/*---------operations-------*/
void	to_swap(t_stack *a);
void	to_rotate(t_stack *a);
void	to_push(t_stack *a, t_stack *b);
void	to_rev_rotate(t_stack *a);
void	to_rrr(t_stack *a, t_stack *b);
void	to_rr(t_stack *a, t_stack *b);
void	to_ss(t_stack *a, t_stack *b);
/*------error_handling------*/
void	final_check_bonus(char *arg);
void	ft_check_duplicate_bonus(t_stack a);
void	ft_error_bonus(void);
/*-------get_arguments------*/
void	read_inst(t_stack *a, t_stack *b);
void	get_arg_bonus(int ac, char **av, t_stack *a);
/*----------utils-----------*/
int		is_sorted(t_stack *stack);
void	ft_free_bonus(char	*arg);

#endif