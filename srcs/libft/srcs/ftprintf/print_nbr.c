/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:14 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 23:33:28 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
		if (n < 0)
			n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

int	print_unsigned(unsigned int nbr)
{
	unsigned int	n;

	n = nbr;
	if (nbr < 10)
		print_char(nbr + '0');
	else
	{
		print_int(nbr / 10);
		print_int(nbr % 10);
	}
	return (digits(n));
}

int	print_int(int nbr)
{
	int	n;

	n = nbr;
	if (nbr == -2147483648)
		print_string("-2147483648");
	else
	{
		if (nbr < 0)
		{
			print_char('-');
			nbr = nbr * -1;
		}
		if (nbr >= 10)
		{
			print_int(nbr / 10);
			print_int(nbr % 10);
		}
		else
			print_char(nbr + '0');
	}
	return (digits(n));
}

int	print_hexa(unsigned long nbr, char c)
{
	char	*symbol;
	int		count;

	count = 0;
	if (c == 'x')
		symbol = "0123456789abcdef";
	else if (c == 'X')
		symbol = "0123456789ABCDEF";
	if (nbr <= 15)
		count += print_char(symbol[nbr]);
	else
	{
		count += print_hexa(nbr / 16, c);
		count += print_hexa(nbr % 16, c);
	}
	return (count);
}
