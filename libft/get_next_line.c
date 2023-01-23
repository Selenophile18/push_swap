/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:07:57 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 16:15:43 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static int	check(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	f_bzero(void *str, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	while (i < n)
		s[i++] = 0;
}

char	*readfunc(int fd, int r, char	*hold)
{
	char	*buff;

	buff = f_calloc((BUFFER_SIZE + 1), 1);
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			if (hold)
				free (hold);
			free (buff);
			return (NULL);
		}
		if (!hold)
			hold = f_calloc((BUFFER_SIZE + 1), 1);
		if (check(buff) == 1)
		{	
			hold = f_strjoin(hold, buff);
			break ;
		}
		hold = f_strjoin(hold, buff);
		f_bzero(buff, BUFFER_SIZE);
	}
	free (buff);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*line;
	char		*tmp;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == 2147483647)
		return (NULL);
	r = 1;
	hold = readfunc(fd, r, hold);
	if (!hold)
		return (NULL);
	line = newres(hold);
	tmp = hold;
	hold = holdrest(tmp);
	return (line);
}
