/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:09:04 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/11 14:30:57 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_and_free(char *buffer, char *tmp_buffer)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, tmp_buffer);
	free(buffer);
	return (tmp);
}

static char	*read_file(int fd, char *buffer)
{
	char	*tmp_buffer;
	ssize_t	b_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && !ft_strchr(tmp_buffer, '\n'))
	{
		b_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(tmp_buffer);
			free(buffer);
			return (NULL);
		}
		tmp_buffer[b_read] = '\0';
		buffer = join_and_free(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	return (buffer);
}

static char	*create_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

static char	*sanitize_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = create_line(buffer);
	buffer = sanitize_buffer(buffer);
	return (line);
}
