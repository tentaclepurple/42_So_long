/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:53:20 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 13:30:07 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_box *b)
{
	b->res = 80;
	b->w = ft_strlen(b->map[0]);
	b->h = 0;
	while (b->map[b->h])
		b->h++;
	b->mlx_ptr = mlx_init();
	b->win_ptr = mlx_new_window(b->mlx_ptr, b->w * b->res, b->h * b->res, \
		"My Zombie Game");
	b->img = mlx_new_image(b->mlx_ptr, b->w * b->res, b->h * b->res);
	ft_declare_images(b);
}

void	ft_declare_images(t_box *b)
{
	b->grnd = mlx_xpm_file_to_image(b->mlx_ptr, "textures/gnd6.xpm", \
		&b->res, &b->res);
	b->wall = mlx_xpm_file_to_image(b->mlx_ptr, "textures/wall.xpm", \
		&b->res, &b->res);
	b->ex = mlx_xpm_file_to_image(b->mlx_ptr, "textures/ex.xpm", \
		&b->res, &b->res);
	b->pl = mlx_xpm_file_to_image(b->mlx_ptr, "textures/pl.xpm", \
		&b->res, &b->res);
	b->col = mlx_xpm_file_to_image(b->mlx_ptr, "textures/col.xpm", \
		&b->res, &b->res);
	b->exwait = 0;
	mlx_loop_hook(b->mlx_ptr, lhook, b);
	mlx_key_hook(b->win_ptr, khook, b);
	mlx_hook(b->win_ptr, 17, 0, end, b);
}

/*
	pinta el suelo del mapa, todo ground
*/
void	pimages_grnd(t_box *b)
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
void	pimages_2(t_box *b)
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

void	pimages_pl(t_box *b)
{
	int	i;
	int	j;

	i = 0;
	while (b->map[i])
	{
		j = 0;
		while (b->map[i][j])
		{
			if (b->map[i][j] == 'P')
				mlx_put_image_to_window(b->mlx_ptr, b->win_ptr, b->pl, \
					b->coorp[1] * b->res, b->coorp[0] * b->res);
			j++;
		}
		i++;
	}
}
