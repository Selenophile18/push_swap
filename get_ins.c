/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:26:54 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 20:28:35 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

char	*get_inst(void)
{
	char	*ins;
	char	*s;

	ins = get_next_line(0);
	s = 0;
	while (ins)
	{
		s = ft_strjoin(s, ins);
		free (ins);
		ins = get_next_line(0);
	}
	return (ins);
}

void	read_inst(t_stack *a, t_stack *b)
{
	char	**ins;
	char	*op;
	int		len;
	int		i;

	op = get_inst();
	ins = ft_split(op, '\n');
	i = 0;
	while (ins && ins[i])
	{
		len = ft_strlen(ins[i]);
		if (!ft_strncmp(ins[i], "sa", len))
			to_swap(a);
		else if (!ft_strncmp(ins[i], "sb", len))
			to_swap(b);
		else if (!ft_strncmp(ins[i], "ra", len))
			to_rotate(a);
		else if (!ft_strncmp(ins[i], "rb", len))
			to_rotate(b);
		else if (!ft_strncmp(ins[i], "rra", len))
			to_rev_rotate(a);
		else if (!ft_strncmp(ins[i], "rrb", len))
			to_rev_rotate(b);
		else if (!ft_strncmp(ins[i], "ss", len))
			to_ss(a, b);
		else if (!ft_strncmp(ins[i], "rr", len))
			to_rr(a, b);
		else if (!ft_strncmp(ins[i], "rrr", len))
			to_rrr(a, b);
		else
			ft_error_bonus();
		i++;
	}
	if (is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}