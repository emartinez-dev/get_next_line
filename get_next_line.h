/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:58:16 by franmart          #+#    #+#             */
/*   Updated: 2022/10/08 18:04:09 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
unsigned int	ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strchr(const char *s, int c);
char			*ft_get_line(char *s1);
char			*ft_new_buffer(char *s1);

#	endif
