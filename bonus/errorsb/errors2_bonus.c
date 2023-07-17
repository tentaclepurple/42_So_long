/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:09:06 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 11:46:53 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	error_perimeterb(char **mat)
{
	ft_printf("Error\nMap is not surrounded by walls\n");
	free_matb(mat);
	exit (-1);
}

void	error_fileb(void)
{
	ft_printf("Error\nWrong file\n");
	exit (-1);
}

void	error_pathb(void)
{
	ft_printf("Error\nCollectables or Exit can´t be reached");
	exit (-1);
}
