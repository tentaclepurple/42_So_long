/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:10:35 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 13:06:05 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
	pinta el suelo del mapa, todo ground
*/
void	pimages_grndb(t_box *b)
{
	int		i;
	int		j;

	i = 0;
	while (b->map[i])
	{
		j = 0;
		while (b->map[i][j])
		{
			mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->grnd, \
				j * b->res, i * b->res);
			j++;
		}
		i++;
	}
}

/* 
	superpone el resto de imagenes (paredes, jugador, collect, exit)
*/
void	pimages_2b(t_box *b)
{
	int	i;
	int	j;

	i = 0;
	while (b->map[i])
	{
		j = 0;
		while (b->map[i][j])
		{
			if (b->map[i][j] == '1')
				mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->wall, \
					j * b->res, i * b->res);
			else if (b->map[i][j] == 'E')
				mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->ex, \
					j * b->res, i * b->res);
			else if (b->map[i][j] == 'C')
				mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->col, \
					j * b->res, i * b->res);
			j++;
		}
		i++;
	}
}

void	pimages_plb(t_box *b)
{
	mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->pl, \
		b->coorp[1] * b->res, b->coorp[0] * b->res);
}

void	pimages_foesb(t_box *b)
{
	ft_anim_foe1b(b);
	mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->foe1, \
		b->coorf1[1] * b->res, b->coorf1[0] * b->res);
	ft_anim_foe2b(b);
	mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->foe2, \
		b->coorf2[1] * b->res, b->coorf2[0] * b->res);
}
