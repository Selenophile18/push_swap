/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:51:03 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/09 12:41:39 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static	unsigned int	len(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	l;
	long			nb;
	char			*str;

	nb = n;
	l = len(nb);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	str[l] = '\0';
	while (nb != 0)
	{
		str[--l] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
