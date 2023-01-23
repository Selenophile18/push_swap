/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:36:37 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/08 18:56:17 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static	unsigned int	strs_num(char const	*s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static	unsigned int	strs_len(const char	*s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] && s[i] != c)
	{
		l++;
		i++;
	}
	return (l);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		w;
	int		len;
	int		i;
	int		strsnum;

	if (!s)
		return (NULL);
	strsnum = strs_num(s, c);
	split = (char **)malloc(sizeof(char **) * (strsnum + 1));
	if (!split)
		return (0);
	i = 0;
	w = 0;
	while (strsnum--)
	{
		while (s[i] == c)
			i++;
		len = strs_len(s, c, i);
		split[w] = ft_substr(s, i, len);
		i += len;
		w++;
	}
	split[w] = 0;
	return (split);
}
