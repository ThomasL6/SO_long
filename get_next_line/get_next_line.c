/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:21:47 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/10 13:21:49 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_stradd(char *str, char *buff, int size)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len + size + 1));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		ret[len + i] = buff[i];
		i++;
	}
	ret[len + i] = '\0';
	free(str);
	return (ret);
}

int	get_next_line(int fd, char **str)
{
	char	buff[BUFFER_SIZE];
	int		ret;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff, ret);
		if (!*str)
			return (-1);
		if (ft_strchr(buff, '\n'))
			return (1);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}
