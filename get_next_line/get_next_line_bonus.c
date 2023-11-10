/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:01:56 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/17 10:02:00 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_freejoin(char *chaine, char *buff)
{
	char	*temp;

	temp = ft_strjoin(chaine, buff);
	free(chaine);
	return (temp);
}

char	*ft_read_and_save(char	*chaine, int fd)
{
	int		readbytes;
	char	*buff;

	if (!chaine)
		chaine = ft_calloc(1, 1);
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[readbytes] = 0;
		chaine = ft_freejoin(chaine, buff);
		if (ft_strchr(chaine, '\n'))
			break ;
	}
	free (buff);
	return (chaine);
}

char	*ft_get_line(char *chaine)
{
	int		index;
	char	*count;

	index = 0;
	if (!chaine[index])
		return (NULL);
	while (chaine[index] != '\0' && chaine[index] != '\n')
		index++;
	count = ft_calloc(sizeof(char), index + 2);
	if (!count)
		return (NULL);
	index = 0;
	while (chaine[index] != '\0' && chaine[index] != '\n')
	{
		count[index] = chaine[index];
		index++;
	}
	if (chaine[index] == '\n' && chaine[index])
		count[index++] = '\n';
	return (count);
}

char	*ft_stock(char *chaine)
{
	int		index;
	int		c;
	char	*stock;

	index = 0;
	c = 0;
	while (chaine[index] != '\0' && chaine[index] != '\n')
		index++;
	if (!chaine[index])
	{
		free(chaine);
		return (NULL);
	}
	stock = ft_calloc(sizeof(char), ft_strlen(chaine) - index + 1);
	if (!stock)
		return (NULL);
	index++;
	while (chaine[index] != '\0')
		stock[c++] = chaine[index++];
	free(chaine);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*chaine[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	chaine[fd] = ft_read_and_save(chaine[fd], fd);
	if (!chaine[fd])
		return (NULL);
	line = ft_get_line(chaine[fd]);
	chaine[fd] = ft_stock(chaine[fd]);
	return (line);
}
