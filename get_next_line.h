/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:09:11 by franmart          #+#    #+#             */
/*   Updated: 2022/12/15 18:59:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# elif BUFFER_SIZE < 1
#  error "BUFFER_SIZE must be a positive integer"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../include/libft.h"

char			*ft_gnl(int fd);

#	endif
