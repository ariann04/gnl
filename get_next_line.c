/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:33:02 by ls                #+#    #+#             */
/*   Updated: 2024/06/20 19:48:57 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_storage(char *storage)
{
	char	*remind;
	int		len;

	len = jumplen(storage);
	if (len == -1)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	remind = ft_substr(storage, len + 1, (ft_strlen(storage) - len));
	free(storage);
	storage = NULL;
	return (remind);
}

char	*new_line(char *storage)
{
	char	*line;
	int		len;

	len = jumplen(storage);
	if (len == -1)
		return (NULL);
	line = ft_substr(storage, 0, len + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	char	*buffer;
	int		status;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	status = 1;
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	buffer[0] = '\0';
	while (status > 0 && !ft_strchr(buffer, '\n'))
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status > 0)
		{
			buffer[status] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (status == -1 || status == 0)
		return (free(storage), storage = NULL, NULL);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
	{
		storage = readbuf(fd, storage);
	}
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = cut_storage(storage);
	return (line);
}

/*int	main(void)
{
	#include <fcntl.h>

	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
