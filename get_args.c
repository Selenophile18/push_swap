/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:07:42 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/12 18:49:37 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_free(char	**av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

t_list	*get_int(int ac, char **av, t_list	*node)
{
	int		i;
	t_list	*temp;
	t_list	*iter;

	temp = node;
	iter = node;
	i = 0;
	while (i < ac && av[i])
	{
		ft_lstadd_back(&node, ft_lstnew(ft_atoi(av[i])));
		node = node->next;
		i++;
	}
	return (temp);
}

t_list	*get_arg(int ac, char **av, t_num *d)
{
	int		i;
	int		j;
	t_list	*stack_a;
	char	**arg;

	d->arg_num = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		arg = ft_split(av[i], 32);
		while (arg[j])
			j++;
		final_check(j, arg);
		d->arg_num += j;
		if (i == 1)
			stack_a = get_int(j, arg + 1, ft_lstnew(ft_atoi(arg[0])));
		else
			stack_a = get_int(j, arg, stack_a);
		ft_free(arg);
		i++;
	}
	ft_check_duplicate(stack_a);
	return (stack_a);
}
