/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:53:01 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 23:07:03 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//pass checking stage then return value 1
int	c_file_format(char *filename)
{
	char	*tmp;

	tmp = ft_strnstr(filename, ".ber", ft_strlen(filename))
	if (!tmp)
		return (0);
	return (1);
}