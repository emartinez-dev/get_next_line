/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:51 by franmart          #+#    #+#             */
/*   Updated: 2022/11/05 14:56:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Concats the old buffer to the new read buffer and frees the old one.
 * 
 * @param buffer old buffer
 * @param tmp_buff new buffer
 * @return char* joined old and new buffer
 */
char	*ft_join_and_free(char *buffer, char *tmp_buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, tmp_buff);
	free(buffer);
	return (temp);
}

/**
 * @brief Travels the buffer and if there is any newline char, returns it.
 * 
 * @param buffer acummulated read string
 * @return char* of the line 
 */
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

/**
 * @brief Reads BUFFER_SIZE bytes from the given file descriptor and adds it to
 * 			the buffer variable until it finds a newline char or the string ends
 * 
 * @param fd file descriptor of the given text file
 * @param buffer address passed by the main function. If buffer is empty, 
 * 					ft_read_file allocates memory for an empty string.
 * @return char* acummulated string of chars read
 */
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

/**
 * @brief Updates the old buffer removing the string that ft_get_line returned.
 * 			The new buffer can be an empty string
 * 
 * @param buffer old buffer
 * @return char* new buffer 
 */
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

/**
 * @brief Returns the next line of a given file descriptor
 * 
 * @param fd file opened
 * @return char* 
 */
char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
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
