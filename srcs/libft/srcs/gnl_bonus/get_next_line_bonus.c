/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:34:31 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/13 23:11:31 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*recoordinate(char *str)
{
	char	*temp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(str) - i, sizeof(char));
	while (str[++i])
		temp[j++] = str[i];
	free(str);
	return (temp);
}

char	*get_line(char *str)
{
	char	*temp;
	int		i;
	int		len;

	i = -1;
	len = 0;
	if (!*str)
		return (NULL);
	while (*str && *str != '\n')
	{
		++str;
		++len;
	}
	temp = ft_calloc(len + 2, sizeof(char));
	str -= len;
	while (str[++i] && str[i] != '\n')
		temp[i] = str[i];
	if (str[i] && str[i] == '\n')
		temp[i] = '\n';
	return (temp);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = joint_str(str, buffer);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	str = get_line(buffer[fd]);
	buffer[fd] = recoordinate(buffer[fd]);
	return (str);
}

// int main(void)
// {
// 	int	fd;
// 	int	fd1;
// 	int	fd2;
	
// 	fd = open("empty.txt", O_RDONLY);
// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("empty.txt", O_RDONLY);

// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd));
	
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
	
// 	return (0);
// }
