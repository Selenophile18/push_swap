/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:23:43 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 16:03:19 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	*f_calloc(size_t n, size_t size)
{
	void	*tab;

	if (size && n >= SIZE_MAX / size)
		return (NULL);
	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	f_bzero(tab, n * size);
	return (tab);
}

size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*newres(char	*s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (!f_strlen(s))
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	res = f_calloc((i + 2), 1);
	if (!res)
	{
		free (s);
		return (NULL);
	}
	j = 0;
	i++;
	while (i--)
	{
		res[j] = s[j];
		j++;
	}
	return (res);
}

char	*holdrest(char	*s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!f_strlen(s))
	{
		free (s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	res = f_calloc((f_strlen(s) - i + 1), 1);
	if (!res)
	{
		free (s);
		return (NULL);
	}
	while (s[i])
		res[j++] = s[++i];
	free (s);
	return (res);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(f_strlen(s1) + f_strlen(s2) + 1);
	if (str == NULL)
	{
		free (s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}
