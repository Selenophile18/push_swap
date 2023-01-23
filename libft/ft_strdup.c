/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:38:56 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/08 18:39:01 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		l;

	l = ft_strlen(str) + 1;
	dup = (char *)malloc(l);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, str, l);
	return (dup);
}
