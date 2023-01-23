/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:00:42 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:30 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*newres(char *s);
char	*f_strjoin(char *s1, char *s2);
size_t	f_strlen(const char *str);
char	*holdrest(char	*s);
void	*f_calloc(size_t n, size_t size);
void	f_bzero(void *str, size_t n);
char	*readfunc(int fd, int r, char	*hold);

#endif