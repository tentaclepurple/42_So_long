/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:15:42 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:15:23 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_anim_colb(t_box *b)
{
	static int	i = 1;

	if (i % 10 == 0)
		ml_img_colb(b, "bonus/textures/col/c_bn0.xpm");
	if (i % 20 == 0)
		ml_img_colb(b, "bonus/textures/col/c_bn1.xpm");
	if (i % 30 == 0)
		ml_img_colb(b, "bonus/textures/col/c_bn2.xpm");
	if (i % 40 == 0)
		ml_img_colb(b, "bonus/textures/col/c_bn3.xpm");
	if (i % 50 == 0)
		ml_img_colb(b, "bonus/textures/col/c_bnb4.xpm");
	if (i % 60 == 0)
	{
		ml_img_colb(b, "bonus/textures/col/c_bnb7.xpm");
		i = 0;
	}
	i++;
}

void	ft_anim_plb(t_box *b)
{
	static int	i = 1;

	if (i % 10 == 0)
		ml_img_plb(b, "bonus/textures/pl/m_id1.xpm");
	if (i % 20 == 0)
		ml_img_plb(b, "bonus/textures/pl/m_id2.xpm");
	if (i % 30 == 0)
		ml_img_plb(b, "bonus/textures/pl/m_id3.xpm");
	if (i % 40 == 0)
		ml_img_plb(b, "bonus/textures/pl/m_id4.xpm");
	if (i % 50 == 0)
		ml_img_plb(b, "bonus/textures/pl/m_id5.xpm");
	if (i % 60 == 0)
	{
		ml_img_plb(b, "bonus/textures/pl/m_id7.xpm");
		i = 0;
	}
	i++;
}

void	ft_anim_eatb(t_box *b)
{
	static int	i = 1;

	if (i % 7 == 0)
		ml_img_plb(b, "bonus/textures/pl/b_m0.xpm");
	if (i % 14 == 0)
		ml_img_plb(b, "bonus/textures/pl/b_m1.xpm");
	if (i % 21 == 0)
		ml_img_plb(b, "bonus/textures/pl/b_m2.xpm");
	if (i % 28 == 0)
		ml_img_plb(b, "bonus/textures/pl/b_m3.xpm");
	if (i % 35 == 0)
		ml_img_plb(b, "bonus/textures/pl/b_m4.xpm");
	if (i % 42 == 0)
	{
		ml_img_plb(b, "bonus/textures/pl/b_m5.xpm");
		i = 0;
		b->swpl = 0;
	}
	i++;
}

void	ft_anim_exb(t_box *b)
{
	static int	i = 1;

	if (i % 20 == 0)
		ml_img_exb(b, "bonus/textures/ex/exp_03.xpm");
	if (i % 40 == 0)
		ml_img_exb(b, "bonus/textures/ex/exp_02.xpm");
	if (i % 60 == 0)
		ml_img_exb(b, "bonus/textures/ex/exp_04.xpm");
	if (i % 80 == 0)
		ml_img_exb(b, "bonus/textures/ex/exp_03.xpm");
	if (i % 100 == 0)
	{
		ml_img_exb(b, "bonus/textures/ex/exp_05.xpm");
		i = 0;
	}
	i++;
}

void	ft_anim_foe2b(t_box *b)
{
	static int	i = 1;

	if (b->f2d == 'r')
	{
		if (i % 10 == 0)
			ml_img_foe2b(b, "bonus/textures/foe/pld_0.xpm");
		if (i % 20 == 0)
		{
			ml_img_foe2b(b, "bonus/textures/foe/pld_1.xpm");
			i = 0;
		}
	}
	if (b->f2d == 'l')
	{
		if (i % 10 == 0)
			ml_img_foe2b(b, "bonus/textures/foe/pli_0.xpm");
		if (i % 20 == 0)
		{
			ml_img_foe2b(b, "bonus/textures/foe/pli_1.xpm");
			i = 0;
		}
	}
	i++;
}
