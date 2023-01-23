/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:30:54 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/09 13:18:39 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while ((d || s) && i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
