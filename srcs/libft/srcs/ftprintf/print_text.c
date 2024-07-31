/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:46 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 23:33:31 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	char	*temp;

	if (!s)
		s = "(null)";
	temp = s;
	while (*s)
		write(1, s++, 1);
	return (ft_strlen(temp));
}

int	print_address(void *ptr)
{
	int	count;

	count = 0;
	count += print_string("0x");
	count += print_hexa((unsigned long)ptr, 'x');
	return (count);
}
