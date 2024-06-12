/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:44:02 by ls                #+#    #+#             */
/*   Updated: 2024/06/12 20:30:08 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*readbuf(int fd, char *storage);
char	*new_line(char *storage);
char	*cut_storage(char *storage);
int	ft_strlen(char *str);
char	*ft_strjoin(char *storage, char *buffer);
char	*ft_strchr(char *storage, char c);
char	*ft_substr(char *storage, int start, int len);
#endif
