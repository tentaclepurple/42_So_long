/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:22:37 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:18:14 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	movementb(t_box *b, int ni, int nj)
{
	static int	i = 1;

	free(b->stps);
	b->stps = ft_itoa(i);
	i++;
	b->coorp[0] = ni;
	b->coorp[1] = nj;
	if (b->map[ni][nj] == 'C')
	{
		b->numc--;
		b->map[ni][nj] = '0';
		b->swpl = 1;
	}
	if (b->map[ni][nj] == 'E' && b->numc == 0)
		b->exwait++;
}

/*  Cuando se pulsan los controles, comprueba que puede desplazarse y se mueve
    Controles flechas:
        up: 126 
        left: 123
        right: 124
        down: 125
*/
int	khookb(int keycode, t_box *b)
{
	if (keycode == 126 && b->map[b->coorp[0] - 1][b->coorp[1]] != '1')
		movementb(b, b->coorp[0] - 1, b->coorp[1]);
	else if (keycode == 123 && b->map[b->coorp[0]][b->coorp[1] - 1] != '1')
		movementb(b, b->coorp[0], b->coorp[1] - 1);
	else if (keycode == 124 && b->map[b->coorp[0]][b->coorp[1] + 1] != '1')
		movementb(b, b->coorp[0], b->coorp[1] + 1);
	else if (keycode == 125 && b->map[b->coorp[0] + 1][b->coorp[1]] != '1')
		movementb(b, b->coorp[0] + 1, b->coorp[1]);
	else if (keycode == 53)
		endb(b);
	return (0);
}

int	lhookb(t_box *b)
{
	deadb(b);
	ft_anim_foe2b(b);
	ft_foe1_movb(b);
	ft_foe2_movb(b);
	ft_anim_colb(b);
	pimages_grndb(b);
	ft_anim_exb(b);
	pimages_2b(b);
	pimages_foesb(b);
	if (b->swpl == 0)
		ft_anim_plb(b);
	if (b->swpl == 1)
		ft_anim_eatb(b);
	pimages_plb(b);
	mlx_string_put(b->mlx_ptr, b->win_ptr, 25, 40, 16777215, b->stps);
	exit_waitb(b);
	return (0);
}
