/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:51 by franmart          #+#    #+#             */
/*   Updated: 2022/10/09 19:26:40 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (read_size > 0)
	{
		read_size = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp_buff);
			return (0);
		}
		tmp_buff[read_size] = '\0';
		buffer = ft_join_and_free(buffer, tmp_buff);
		if (ft_strchr(buffer, '\n'))
		{
			free(tmp_buff);
			return (buffer);
		}
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
	static char		*buffer;
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (0);
	str = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (str);
}
/*
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
*/
