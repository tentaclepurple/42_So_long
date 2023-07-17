/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:09:06 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:00:53 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_perimeter(char **mat)
{
	ft_printf("Error\nMap is not surrounded by walls\n");
	free_mat(mat);
	exit (-1);
}

void	error_file(void)
{
	ft_printf("Error\nWrong file\n");
	exit (-1);
}

void	error_path(void)
{
	ft_printf("Error\nCollectables or Exit can´t be reached");
	exit (-1);
}
