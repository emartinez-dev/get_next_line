/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:51 by franmart          #+#    #+#             */
/*   Updated: 2022/10/08 12:11:16 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// borrar estas:
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

char	*ft_read(int fd, char *buffer)
{
	char		*tmp_buff;
	int			status;

	tmp_buff = malloc(BUFFER_SIZE + 1);
	if (buffer == 0)
		return (0);
	if (!fd || !BUFFER_SIZE || !tmp_buff)
		return (0);
	while (ft_strchr(buffer, '\n') == 0 && status > 0)
	{
		status = read(fd, tmp_buff, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			free(tmp_buff);
			return (0);
		}
		buffer = ft_strjoin(buffer, tmp_buff);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = "";
	char		*str;
	int			i;
	
	i = 0;	
	if (buffer == 0)
		return (0);
	else
		ft_read(fd, buffer);
	if (ft_strchr(buffer, '\n') == 0)
	{
		buffer = 0;
		return (buffer);
	}
	while (buffer[i] != '\n')
		i++;
	str = ft_substr(buffer, 0, i + 1);
	buffer = ft_substr(buffer, i + 1, ft_strlen(buffer));
	printf("%s", str);
	return (str);
}

/*int	main(void)
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
