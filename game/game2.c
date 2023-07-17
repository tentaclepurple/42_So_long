/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:22:37 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:34:10 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement(t_box *b, int ni, int nj)
{
	static int	i = 1;

	ft_printf("%i\n", i);
	i++;
	b->coorp[0] = ni;
	b->coorp[1] = nj;
	if (b->map[ni][nj] == 'C')
	{
		b->numc--;
		b->map[ni][nj] = '0';
	}
	if (b->map[ni][nj] == 'E' && b->numc == 0)
	{
		b->exwait = 1;
	}
}

/*  Cuando se pulsan los controles, comprueba que puede desplazarse y se mueve
    Controles flechas:
        up: 126 
        left: 123
        right: 124
        down: 125
*/
int	khook(int keycode, t_box *b)
{
	if (keycode == 126 && b->map[b->coorp[0] - 1][b->coorp[1]] != '1')
		movement(b, b->coorp[0] - 1, b->coorp[1]);
	else if (keycode == 123 && b->map[b->coorp[0]][b->coorp[1] - 1] != '1')
		movement(b, b->coorp[0], b->coorp[1] - 1);
	else if (keycode == 124 && b->map[b->coorp[0]][b->coorp[1] + 1] != '1')
		movement(b, b->coorp[0], b->coorp[1] + 1);
	else if (keycode == 125 && b->map[b->coorp[0] + 1][b->coorp[1]] != '1')
		movement(b, b->coorp[0] + 1, b->coorp[1]);
	else if (keycode == 53)
		end(b);
	return (0);
}

int	lhook(t_box *b)
{
	pimages_grnd(b);
	pimages_2(b);
	pimages_pl(b);
	if (b->exwait == 10)
		end(b);
	if (b->exwait > 0)
		b->exwait++;
	return (0);
}
