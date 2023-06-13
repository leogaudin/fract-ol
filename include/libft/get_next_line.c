/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:30:18 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/09 13:41:44 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief
 * Takes the current stash and a buffer, and returns
 * the appended stash.
 *
 * @param    stash     the stash to append
 * @param    buffer    the buffer to append to the stash
 * @return   char*     the updated stash
 */
char	*append_to_stash(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

/**
 * @brief
 * Reads from a file descriptor and appends its contents
 * (until a '\n' is encountered) to the provided stash.
 *
 * If the stash is empty (e.g. because it is the first call
 * of get_next_line), initialises with calloc.
 *
 * If the read fails, frees the buffer and the stash, then
 * returns NULL.
 *
 * @param    fd        the descriptor of the file to read
 * @param    stash     the stash to append
 * @return   char*     the appended stash
 */
char	*read_to_stash(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	read_bytes = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (read_bytes > 0)
	{
		if (read(fd, 0, 0) == -1)
		{
			free(stash);
			free(buffer);
			return (0);
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		stash = append_to_stash(stash, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	free(buffer);
	return (stash);
}

/**
 * @brief
 * Takes the provided stash and removes the characters
 * before the first '\n' (included), then returns the
 * updated version.
 *
 * If the stash has only one line left, it is freed and
 * the return value is NULL.
 *
 * @param    stash
 * @param    nl_index  the index of the '\n'
 * @return   char*     the purged stash
 */
char	*get_new_stash(char *stash, int nl_index)
{
	char	*new_stash;
	int		i;

	if (stash[nl_index] == '\0')
	{
		free(stash);
		return (0);
	}
	new_stash = ft_calloc(ft_strlen(stash) - nl_index + 1, sizeof(char));
	nl_index++;
	i = 0;
	while (stash[nl_index])
	{
		new_stash[i] = stash[nl_index];
		i++;
		nl_index++;
	}
	free(stash);
	return (new_stash);
}

/**
 * @brief
 * Takes the stash (i.e. accumulation of read buffers)
 * and returns all of the characters before '\n',
 * including the latter.
 *
 * If the stash is empty, it returns a null pointer.
 *
 *
 * @param    stash
 * @return   char*     the first "line" of the stash.
 */
char	*stash_to_line(char *stash)
{
	char	*line;
	int		nl_index;
	int		i;

	if (stash[0] == '\0')
		return (0);
	nl_index = get_nl_index(stash);
	line = ft_calloc(nl_index + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = stash[i];
	return (line);
}

/**
 * @brief
 * Takes a file descriptor and returns the next line
 * encountered.
 *
 * If:
 * - the file descriptor is invalid,
 * - BUFFER_SIZE is null or negative,
 * - read() on fd fails,
 * frees the stash and returns NULL.
 *
 * @param    fd        the descriptor of the file to read
 * @return   char*     explanation
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (!(fd >= 0 && BUFFER_SIZE > 0) || read(fd, 0, 0) < 0)
	{
		free(stash);
		return (0);
	}
	stash = read_to_stash(fd, stash);
	line = stash_to_line(stash);
	stash = get_new_stash(stash, get_nl_index(stash));
	return (line);
}
