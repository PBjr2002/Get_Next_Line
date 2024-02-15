/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:28 by pauberna          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:06 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_read_file(int fd, char *buffer, char *result)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == 0)
		return (0);
	else if (bytes == -1)
	{
		if (result != NULL)
			free(result);
		return (-1);
	}
	return (bytes);
}

char	*use_remains(char *remains, char *buffer)
{
	char		*result;
	size_t		len;
	size_t		n;
	size_t		i;

	len = ft_strlen(remains) + ft_strlen(buffer);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	n = 0;
	i = 0;
	while (remains && remains[i])
	{
		result[n] = remains[i];
		n++;
		i++;
	}
	i = 0;
	while (buffer[i])
		result[n++] = buffer[i++];
	result[n] = '\0';
	free(remains);
	cut_result(result);
	return (result);
}

void	cut_result(char *result)
{
	int	n;

	n = 0;
	while (result[n] && result[n] != '\n')
		n++;
	if (result[n] == '\n')
		n++;
	result[n] = '\0';
}

int	adjust_buffer(char *buffer)
{
	size_t		n;
	size_t		buffer_len;
	size_t		newline;
	int			verify;

	n = 0;
	buffer_len = ft_strlen(buffer);
	newline = 0;
	verify = 0;
	while (buffer[newline] && buffer[newline] != '\n')
		newline++;
	if (buffer[newline] == '\n')
		verify = 1;
	while (n < buffer_len)
	{
		if (newline + n < buffer_len)
		{
			buffer[n] = buffer[newline + n + 1];
			buffer[newline + n + 1] = '\0';
		}
		else
			buffer[n] = '\0';
		n++;
	}
	return (verify);
}
