/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:03:30 by pauberna          #+#    #+#             */
/*   Updated: 2023/11/14 15:18:01 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	int			bytes;

	if (fd >= FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			bytes = ft_read_file(fd, buffer[fd], result);
			if (bytes == -1)
				return (NULL);
			else if (bytes == 0)
				return (result);
		}
		result = use_remains(result, buffer[fd]);
		if (adjust_buffer(buffer[fd]) == 1)
			break ;
	}
	return (result);
}

/* int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	//char	*result;

	i = 1;
	fd = open("teste.txt", O_RDONLY);
	fd2 = open("teste_bonus.txt", O_RDONLY);
	// while (i < 20)
	// {
	// 	result = get_next_line(fd);
	// 	printf("%s",result);
	// 	free(result);
	// 	i++;
	// }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	close (fd);
	return (0);
} */
