/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:51 by franmart          #+#    #+#             */
/*   Updated: 2022/10/09 19:11:44 by franmart         ###   ########.fr       */
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

char	*ft_get_line(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1[i])
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i])
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read(int fd, char *buffer)
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

char	*ft_new_buffer(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (0);
	}
	str = ft_calloc(ft_strlen(s1) - i + 1, sizeof(char));
	if (!str)
		return (0);
	i++;
	while (s1[i])
		str[j++] = s1[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_read(fd, buffer);
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
