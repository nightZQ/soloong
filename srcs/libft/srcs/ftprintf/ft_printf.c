/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:50:45 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 23:33:25 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	determine_specifier(const char *ptr, va_list ap)
{
	int	counter;

	counter = 0;
	if (*ptr == 'c')
		counter += print_char(va_arg(ap, int));
	else if (*ptr == 's')
		counter += print_string(va_arg(ap, char *));
	else if (*ptr == 'p')
		counter += print_address(va_arg(ap, void *));
	else if (*ptr == 'd' || *ptr == 'i')
		counter += print_int(va_arg(ap, int));
	else if (*ptr == 'u')
		counter += print_unsigned(va_arg(ap, unsigned int));
	else if (*ptr == 'x')
		counter += print_hexa(va_arg(ap, unsigned int), 'x');
	else if (*ptr == 'X')
		counter += print_hexa(va_arg(ap, unsigned int), 'X');
	else if (*ptr == '%')
		counter += print_char('%');
	return (counter);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, ptr);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			++ptr;
			counter += determine_specifier(ptr, ap);
		}
		else
			counter += write(1, ptr, 1);
		++ptr;
	}
	va_end(ap);
	return (counter);
}
/*
#include <stdio.h>

int main(void)
{
	int	count;
	int	real_counter;
	char	*hi;

	count = ft_printf("%p", &hi);
	printf("\n");
	real_counter = printf("%p", &hi);
	printf("\n");
	printf("\n%d", count);
	printf("\n%d", real_counter);
	return (0);
}
*/
