/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:58 by franmart          #+#    #+#             */
/*   Updated: 2022/10/20 20:43:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_and_free(char *buffer, char *tmp_buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, tmp_buff);
	free(buffer);
	return (temp);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i])
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp_buff;
	int		read_size;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while (read_size > 0 && !(ft_strchr(buffer, '\n')))
	{
		read_size = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp_buff);
			free(buffer);
			return (0);
		}
		tmp_buff[read_size] = '\0';
		buffer = ft_join_and_free(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}

char	*ft_new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*n_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	n_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!n_buffer)
		return (0);
	i++;
	while (buffer[i])
		n_buffer[j++] = buffer[i++];
	n_buffer[j] = '\0';
	free(buffer);
	return (n_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[4096];
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return (0);
	}
	str = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_buffer(buffer[fd]);
	return (str);
}
