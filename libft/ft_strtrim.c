/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:37:26 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/21 23:02:40 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	check_char(char c, char const	*set)
{
	int	i;

	i = 0;
	while (set && set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static int	trimmed_size(char const	*s1, char const	*set)
{
	int	f;
	int	l;
	int	len;

	f = 0;
	while (s1[f] && check_char(s1[f], set) == 0)
		f++;
	l = ft_strlen(s1) - 1;
	while (check_char(s1[l], set) == 0)
		l--;
	len = l - f + 1;
	return (len);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int		len;
	int		t;
	int		i;
	char	*trimmed;

	if (!s1)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	len = trimmed_size(s1, set);
	if (len < 0)
		len = 0;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (check_char(s1[i], set) == 0)
		i++;
	t = 0;
	while (len-- > 0)
		trimmed[t++] = s1[i++];
	trimmed[t] = 0;
	return (trimmed);
}
