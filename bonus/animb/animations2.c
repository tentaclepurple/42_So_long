/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:10:40 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:15:56 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/* 
	Cambia la direccion de mirada del sprite de LeChuck
	segun el random b->rnd1
	0 = up
	1 = down
	2 = left
	3 = right
*/
void	ft_anim_foe1b(t_box *b)
{
	if (b->rnd1 == 0)
		ml_img_foe1b(b, "bonus/textures/foe/lcb_0.xpm");
	if (b->rnd1 == 1)
		ml_img_foe1b(b, "bonus/textures/foe/lcf_3.xpm");
	if (b->rnd1 == 2)
		ml_img_foe1b(b, "bonus/textures/foe/lcl_0.xpm");
	if (b->rnd1 == 3)
		ml_img_foe1b(b, "bonus/textures/foe/lcr_0.xpm");
}
