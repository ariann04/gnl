/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:07 by ls                #+#    #+#             */
/*   Updated: 2024/06/01 19:08:40 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		*str++;
	}
	return (i);
}
char	*ft_strjoin(char *storage, char *buffer)
{
	char	*str;
	char	*temp;

	str = malloc (sizeof(char) * ft_strlen(buffer) + ft_strlen(storage) + 1);
	if (!str)
		return (NULL);
	temp = str;
	while (*storage)
		*temp++ = *storage++;
	while (*buffer)
		*temp++ = *buffer++;
	temp = '\0';
	return (str);
}
