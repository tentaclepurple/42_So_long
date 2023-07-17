/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:12:55 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:16:19 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ml_img_colb(t_box *b, char *s)
{
	b->col = mlx_xpm_file_to_image(b->mlx_ptr, s, &b->res, &b->res);
}

void	ml_img_plb(t_box *b, char *s)
{
	b->pl = mlx_xpm_file_to_image(b->mlx_ptr, s, &b->res, &b->res);
}

void	ml_img_exb(t_box *b, char *s)
{
	b->ex = mlx_xpm_file_to_image(b->mlx_ptr, s, &b->res, &b->res);
}

void	ml_img_foe2b(t_box *b, char *s)
{
	b->foe2 = mlx_xpm_file_to_image(b->mlx_ptr, s, &b->res, &b->res);
}

void	ml_img_foe1b(t_box *b, char *s)
{
	b->foe1 = mlx_xpm_file_to_image(b->mlx_ptr, s, &b->res, &b->res);
}
