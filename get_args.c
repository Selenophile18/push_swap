/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:07:42 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/21 16:39:12 by hhattaki         ###   ########.fr       */
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

t_stack	*ints(char	*all)
{
	char	**arg;
	t_stack	*a;
	int		i;
	int		s;

	arg = ft_split(all, ' ');
	s = 0;
	while (arg[s])
		s++;
	a = (t_stack *)ft_calloc(s, sizeof(t_stack));
	a->head = ft_lstnew(ft_atoi(arg[0]));
	a->stack = a->head;
	i = 1;
	a->size = 1;
	while (arg[i])
	{
		ft_lstadd_back(&(a)->head, ft_lstnew(ft_atoi(arg[i])));
		a->head = a->head->next;
		a->size++;
		i++;
	}
	a->head = a->stack;
	return (a);
}

t_stack	*get_arg(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*it;
	char	*all;

	i = 0;
	all = 0;
	while (++i < ac)
	{
		all = ft_strjoin(all, " ");
		all = ft_strjoin(all, av[i]);
	}
	final_check(all);
	a = ints(all);
	it = a;
	return (a);
}
