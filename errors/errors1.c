/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:09:06 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:20:15 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_2m_ce(char *str)
{
	ft_printf("Error\nThere is more than one exit or player in the map\n");
	free(str);
	exit (-1);
}

void	error_no_ce(char *str)
{
	ft_printf("Error\nPlayer, Exit or Collectible is missing in the map\n");
	free(str);
	exit (-1);
}

void	error_argc(int argc)
{
	ft_printf("Error\n%i maps/arguments were provided. One is needed\n", \
		argc - 1);
	exit (-1);
}

void	error_invalid_str(char *str)
{
	ft_printf("Error\nInvalid map\n");
	free(str);
	exit (-1);
}

void	error_invalid_mat(char **mat)
{
	ft_printf("Error\nInvalid map or not square\n");
	free_mat(mat);
	exit (-1);
}
