/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:09:53 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 15:54:09 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_duplicate(t_stack a)
{
	t_list	*iter;

	while (a.stack)
	{
		iter = a.stack->next;
		while (iter)
		{
			if (a.stack->content == iter->content)
				ft_error();
			iter = iter->next;
		}
		a.stack = a.stack->next;
	}
	a.stack = a.head;
}

void	get_error(char *s, int t, int i)
{
	int	j;

	j = i;
	while (j < t)
	{
		if (!ft_isdigit(s[j]) && s[i] != '-' && s[i] != '+')
			ft_error();
		j++;
	}
	if ((s[i] == '-' || s[i] == '+') && (!s[i + 1] || !ft_isdigit(s[i + 1])))
		ft_error();
}

char	*str_isdigit(char	*s)
{
	int		i;
	int		t;
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
	get_error(s, t, i);
	av = ft_substr(s, i, t - i);
	return (av);
}

void	max_min(char *str)
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

void	final_check(char *arg)
{
	int		i;
	char	**all;
	char	*temp;

	i = 0;
	all = ft_split(arg, 32);
	while (all[i])
	{
		temp = str_isdigit(all[i]);
		if (ft_strlen(temp) >= 10)
			max_min(temp);
		i++;
		free(temp);
	}
	ft_free(all);
}
