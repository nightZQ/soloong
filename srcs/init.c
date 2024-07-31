/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 03:59:23 by zgoh              #+#    #+#             */
/*   Updated: 2024/07/29 04:15:57 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = ( data->mlx_ptr, data->map.column, 
						data->map.floors, WINDOW);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return (-1);
	}
}