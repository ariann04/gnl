/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:07 by ls                #+#    #+#             */
/*   Updated: 2024/06/16 01:44:49 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return(&((char*)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

int	jumplen(char *storage)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;


	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return(free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *storage, int start, int len)
{
	char	*str;
	int	i;

	i = 0;
	if (!storage)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < start && *storage)
	{
		storage++;
		i++;
	}
	i = 0;
	while (i < len && *storage)
	{
		str[i] = *storage;
		i++;
		storage++;
	}
	str[i] = '\0';
	return (str);
}
