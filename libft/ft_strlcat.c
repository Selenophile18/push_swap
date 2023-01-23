/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:52:27 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/08 18:41:01 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	r;
	size_t	d;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	d = ft_strlen(dest);
	r = d + ft_strlen(src);
	i = 0;
	if (size < d)
		return (size + ft_strlen(src));
	while (dest && src[i] && d < size - 1)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (r);
}
