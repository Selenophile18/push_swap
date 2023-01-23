/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:46:22 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/13 18:50:54 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char	*big, const char	*lil, size_t	len)
{
	int		i;
	size_t	j;

	i = 0;
	if (lil[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == lil[j] && i + j < len)
			j++;
		if (lil[j] == '\0')
			return ((char *)big + i);
		if (i + j >= len)
			break ;
		i++;
	}
	return (NULL);
}
