/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:32:03 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/08 19:44:54 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	while (i < n)
		s[i++] = c;
	return (str);
}
