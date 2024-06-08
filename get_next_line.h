/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:44:02 by ls                #+#    #+#             */
/*   Updated: 2024/06/08 23:38:24 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifdef BUFFER_SIZE
#define BUFFER_SIZE 42
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*readbuf(char *storage, int fd);
char	*new_line(char *storage);
int		*ft_strlen(char *str);
char	*ft_strjoin(char *storage, char *buffer);
char	*strchr(char *storage, char c);
char	*ft_substr(char *storage, int start, int len);
int		ft_strlen(char *str);
#endif
