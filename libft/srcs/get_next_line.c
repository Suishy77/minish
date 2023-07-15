/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:25:18 by aminko            #+#    #+#             */
/*   Updated: 2022/11/30 14:00:22 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	int		readed;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		++i;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		++i;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*next_l;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next_l = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!next_l)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		next_l[j++] = str[i++];
	next_l[j] = '\0';
	free(str);
	return (next_l);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next(str);
	return (line);
}
