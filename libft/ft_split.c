/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:59:49 by thlefebv          #+#    #+#             */
/*   Updated: 2023/04/26 09:59:52 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *) malloc (sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_nbword(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

int	ft_lword(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		size;
	int		word;
	char	**strs;

	i = 0;
	j = -1;
	word = ft_nbword(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_lword(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
			return (NULL);
		i += size;
	}
	strs[j] = NULL;
	free(s);
	return (strs);
}
