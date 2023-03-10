/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:33:53 by hhattaki          #+#    #+#             */
/*   Updated: 2022/10/21 23:03:48 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
