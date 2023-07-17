/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:53:20 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 11:35:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_initb(t_box *b)
{
	b->swpl = 0;
	b->res = 80;
	b->w = ft_strlen(b->map[0]);
	b->h = 0;
	while (b->map[b->h])
		b->h++;
	b->mlx_ptr = mlx_init();
	b->win_ptr = mlx_new_window(b->mlx_ptr, b->w * b->res, b->h * b->res, \
		"Monkey Island: The revenge of LeChuck and Goiko's Mad Dog");
	b->img = mlx_new_image(b->mlx_ptr, b->w * b->res, b->h * b->res);
	ft_declare_imagesb(b);
}

void	ft_declare_imagesb(t_box *b)
{
	b->grnd = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/gnd11.xpm", \
		&b->res, &b->res);
	b->wall = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/bgn00.xpm", \
		&b->res, &b->res);
	b->ex = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/ex/exp_01.xpm", \
		&b->res, &b->res);
	b->pl = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/pl/m_id0.xpm", \
		&b->res, &b->res);
	b->col = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/col/c_bn0.xpm", \
		&b->res, &b->res);
	b->foe1 = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/foe/lcf_0.xpm", \
		&b->res, &b->res);
	b->foe2 = mlx_xpm_file_to_image(b->mlx_ptr, "bonus/textures/foe/pli_0.xpm", \
		&b->res, &b->res);
	b->exwait = 0;
	b->stps = ft_strdup("0");
	mlx_loop_hook(b->mlx_ptr, lhookb, b);
	mlx_key_hook(b->win_ptr, khookb, b);
	mlx_hook(b->win_ptr, 17, 0, endb, b);
}
