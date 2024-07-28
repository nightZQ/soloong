/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:07:58 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/28 23:09:41 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prep_game(char *mapfile)
{
}

int	main(int argc, char *argv)
{
	if (argc < 2)
		exit_game("Please provide along with map file!\n");
	else if (argc == 2 && c_file_format(argv[1]) == 0)
		exit_game("Wrong format, please provide map file in .ber!\n");
	else if (argc == 2 && c_file_format(argv[1]))
		prep_game(argv[1]);
	else
		exit_game("Usage: ./so_long \'map_file\'\n");
	return (0);
}