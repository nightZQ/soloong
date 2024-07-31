/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:38:22 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/13 23:10:06 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
//nothing to be free within this function, as temp is still in use 
//	>str can't be free, because it still have use for recoordinate()
//if statement is to add one '\n' at the end of the line if str have
// >if not, then no need to add

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
//pointer str can't be free within this function, 
// so, it been freed during ft_strjoin
//line 75: if reach the end of the file, buffer will not update to "NULL"
// >it remain the previous result of read().

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	str = get_line(buffer);
	buffer = recoordinate(buffer);
	return (str);
}

// int main(void)
// {
// 	int	fd;

// 	fd = open("empty.txt", O_RDONLY);

// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));

// 	close(fd);
// 	return (0);
// }
