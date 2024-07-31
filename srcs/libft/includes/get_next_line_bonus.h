/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:35:03 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/13 23:09:58 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *str);
char	*get_line(char *str);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*joint_str(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
//ft_strlen, ft_calloc, ft_strchr is all same as libft's,
//but gnl() supposed not using libft function, so dk can combine or not
#endif
