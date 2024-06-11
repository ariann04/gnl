/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:07 by ls                #+#    #+#             */
/*   Updated: 2024/06/09 00:10:33 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(char *storage, char c)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == c)
			return (storage);
		i++;
	}
	if (c == '\0')
		return (storage);
	return (0);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*str;
	char	*temp;

	str = malloc(sizeof(char) * ft_strlen(buffer) + ft_strlen(storage) + 1);
	if (!str)
		return (NULL);
	temp = str;
	while (*storage)
		*temp++ = *storage++;
	while (*buffer)
		*temp++ = *buffer++;
	temp = '\0';
	free(storage);
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
		str[i] = storage;
		i++;
		storage++;
	}
	str[i] = '\0';
	return (str);
}
