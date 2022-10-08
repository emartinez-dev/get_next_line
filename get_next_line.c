/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:51 by franmart          #+#    #+#             */
/*   Updated: 2022/10/08 18:01:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// borrar estas:
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_read(int fd, char *buffer)
{
	char	*tmp_buff;
	int		r_size;

	r_size = 1;
	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
		return (0);
	while (!ft_strchr(buffer, '\n') && r_size != 0)
	{
		r_size = read(fd, tmp_buff, BUFFER_SIZE);
		if (r_size == -1)
		{
			free(tmp_buff);
			return (0);
		}
		tmp_buff[r_size] = '\0';
		buffer = ft_strjoin(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (0);
	str = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}	
	fd = close(fd);
	return (0);
}

