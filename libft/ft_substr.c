/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:53:18 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/13 19:01:06 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	size_t			l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len > l)
		sub = malloc(l + 1);
	else
		sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len-- > 0 && start < l)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
