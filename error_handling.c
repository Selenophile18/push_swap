/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:09:53 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/12 18:51:14 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}

void	ft_check_duplicate(t_list	*stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->content == stack->content)
				ft_error();
			temp = temp->next;
		}
		stack = stack->next;
	}
}

char	*str_isdigit(char	*s)
{
	int		i;
	int		t;
	int		j;
	char	*av;

	i = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (s[i] != '\t' && s[i] != ' ')
			break ;
		i++;
	}
	t = ft_strlen(s) - i;
	while (t >= 0)
	{
		if (s[t] != '\t' && s[t] != ' ')
			break ;
		t--;
	}
	j = i;
	while (j < t)
	{
		if (!ft_isdigit(s[j]) && s[i] != '-' && s[i] != '+')
			ft_error();
		j++;
	}
	if ((s[i] == '-' || s[i] == '+') && (!s[i + 1] || !ft_isdigit(s[i + 1])))
		ft_error();
	av = ft_substr(s, i, t - i);
	return (av);
}

void	max_min(char	*str)
{
	char	*max;
	char	*min;
	int		len;

	len = ft_strlen(str);
	max = ft_calloc(11, 1);
	max = "2147483647";
	min = ft_calloc(12, 1);
	min = "-2147483648";
	if (len > 11)
		ft_error();
	if (str[0] == '-')
	{
		if (ft_strncmp(str, min, len) > 0)
			ft_error();
	}
	else
	{
		if (str[0] == '+')
			str++;
		if (ft_strncmp(str, max, len) > 0)
			ft_error();
	}
}

void	final_check(int ac, char	**av)
{
	int			i;

	i = 0;
	while (av[i] && i < ac)
	{
		av[i] = str_isdigit(av[i]);
		if (ft_strlen(av[i]) >= 10)
			max_min(av[i]);
		i++;
	}
}
