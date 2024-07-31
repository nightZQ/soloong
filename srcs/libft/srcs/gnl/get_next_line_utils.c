/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:41:21 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/13 23:10:59 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*idk;
	size_t		i;
	char		*str;

	i = -1;
	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	idk = (void *)malloc(count * size);
	if (!idk)
		return (NULL);
	str = (char *)idk;
	while (++i < count)
		*(str++) = '\0';
	return (idk);
}

char	*joint_str(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		++i;
	}
	while (s2[j])
		new[i++] = s2[j++];
	free(s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		++s;
	}
	if (character == '\0')
		return ((char *)s);
	return (NULL);
}
