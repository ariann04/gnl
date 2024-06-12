/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:07 by ls                #+#    #+#             */
/*   Updated: 2024/06/12 23:07:09 by tblagoev         ###   ########.fr       */
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

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return 0;
	printf("Str strchar: %s\n", str);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (0);
}

int	strlen1(char *storage)
{
	int	i;

	i = 0;
	while (*storage)
	{
		if (*storage == '\n')
		{
			i++;
			return (i);
		}
		storage++;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*str;
	char	*temp;

	if (!buffer)
		return (NULL);
	if (!storage && *buffer)
	{
		storage = malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	str = malloc(sizeof(char) *
			(ft_strlen(buffer) + ft_strlen(storage) + 1));
	temp = str;
	while (*storage)
		*temp++ = *storage++;
	while (*buffer)
		*temp++ = *buffer++;
	*temp = '\0';
	//free(storage);
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
