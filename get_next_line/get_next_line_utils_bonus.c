/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:28 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/17 10:07:32 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;	
	size_t	index;
	size_t	i;

	i = 0;
	index = 0;
	tab = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!tab)
		return (NULL);
	while (s1[index] != '\0')
	{
		tab[index] = s1[index];
		index++;
	}
	while (s2[i] != '\0')
	{
		tab[index + i] = s2[i];
		i++;
	}
	tab[index + i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	if (c != s[index])
		return (NULL);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (str == 0)
		return (str);
	ft_bzero(str, (nmemb * size));
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char *)s;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}
