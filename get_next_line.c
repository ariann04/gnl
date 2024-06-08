/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:33:02 by ls                #+#    #+#             */
/*   Updated: 2024/06/08 23:41:46 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_storage(char *storage)
{
	char	*ptr;
	char	*remind;
	int	len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		remind = NULL;
		return (free(storage, NULL));
	}
	else
		len = (ptr - storage) + 1;
	remind = ft_substr(storage, len, (ft_strlen(storage) - len));
	if (!storage)
		return (free(storage), NULL);
	return (remind);
}

char *new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int	len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	printf("%i", len);
	line = ft_substr(storage, 0, len);
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
		return (ft_free(storage));
	buffer[0] = '\0';
	while (status > 0 && !ft_strchr(buffer, '\n'))
	{
		status = read (fd, buffer, BUFFER_SIZE);
		if (status > 0)
		{
			buffer[status] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (status == -1)
		return (free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
	{
		storage = readbuf(fd, storage);
	}
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
	{
		free(storage);
		return(NULL);
	}
	storage = cut_storage(storage);
	return(line);		
}

int	main()
{
	int	fd = open(texto.txt, O_RDONLY);
	while (fd != EOF)
	{

	}
	return (0);
}
/*

compilar con las flags -Wall -Wextra -Werror -g3 -fsanitize=address,leak

todo list:


la verificacion se va a hacer en bucle

todos los read deben ser concatenados en un puntero str, usando por ejemplo strjoin.

debes poder gerenciar que si tienes un buffer muy grande pede que
1. hayas leido mas de una linea
o
2. llegaste al final del archivo y no hay mas salto de linea.

en la estatica verificar si existe algo mas luego del salto de linea, generar un substr por ejemplo de la linea hasta el salto de linea y luego desde el salto de linea hasta el final de la string

ejemplo:

"hola como estas\n tu la noche de hoy"


partiendo de la string antes creada deberemos crear 2 strings que serian

str1 = "hola como estas\n"
str2 = " tu la noche de hoy"

es importante que si vas a usar un strjoin o substr en la misma variable no pierdas la referencia, con esto me refiero a:



la siguiente string es un puntero con malloc

"hola"

a dicha string se le va a concatenar "como estas tu\n"

hay que generar un puntero str de respaldo para igualarlo a el primero que contiene "hola" y asi luego de hacer el strjoin a la misma varibale podamos liberar el malloc que estaba en "hola"


char *str = "hola"
char *oldptr = str;
str = strjoin(str, buffer);
free(oldptr);*/
