/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:58:01 by franmart          #+#    #+#             */
/*   Updated: 2022/10/08 10:53:15 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dst_size;
	unsigned int	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= dst_size)
		return (size + src_size);
	while (i < src_size && i + dst_size < size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	str_len;
	unsigned int	i;
	char			*str;

	i = -1;
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(str_len);
	if (!str)
		return (0);
	while (++i < ft_strlen(s1) + 1)
		str[i] = s1[i];
	str[i] = '\0';
	ft_strlcat(str, s2, str_len);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == ch)
		return ((char *)(s + i));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char	*str;

	i = 0;
	if (len > ft_strlen(s))
		str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
