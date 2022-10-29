/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:09:11 by franmart          #+#    #+#             */
/*   Updated: 2022/10/29 23:32:44 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE < 1
#  error "BUFFER_SIZE must be a positive integer"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char			*get_next_line(int fd);
unsigned int	ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strchr(const char *s, int c);
void			ft_bzero(void *s, unsigned int n);
void			*ft_calloc(unsigned int nmemb, unsigned int size);

#	endif
