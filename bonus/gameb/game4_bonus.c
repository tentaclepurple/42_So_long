/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game4_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:10:35 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 13:05:43 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/* 
	LeChuck se mueve según el numero random b->rnd1
	0 = up
	1 = down
	2 = left
	3 = right
*/
void	ft_foe1_movb(t_box *b)
{
	static int	i = 0;

	srandom(time(NULL));
	b->rnd1 = random() % 4;
	if (b->rnd1 == 0 && i % 15 == 0
		&& b->map[b->coorf1[0] - 1][b->coorf1[1]] != '1')
			b->coorf1[0]--;
	if (b->rnd1 == 1 && i % 15 == 0
		&& b->map[b->coorf1[0] + 1][b->coorf1[1]] != '1')
			b->coorf1[0]++;
	if (b->rnd1 == 2 && i % 15 == 0
		&& b->map[b->coorf1[0]][b->coorf1[1] - 1] != '1')
			b->coorf1[1]--;
	if (b->rnd1 == 3 && i % 15 == 0
		&& b->map[b->coorf1[0]][b->coorf1[1] + 1] != '1')
			b->coorf1[1]++;
	i++;
}

/* 
	perrete se mueve según el numero random b->rnd1
	0 = up
	1 = down
	2 = left
	3 = right
*/
void	ft_foe2_movb(t_box *b)
{
	static int	i = 0;

	srandom(time(NULL) * 2);
	b->rnd2 = random() % 4;
	if (b->rnd2 == 0 && i % 15 == 0
		&& b->map[b->coorf2[0] - 1][b->coorf2[1]] != '1')
		b->coorf2[0]--;
	if (b->rnd2 == 1 && i % 15 == 0
		&& b->map[b->coorf2[0] + 1][b->coorf2[1]] != '1')
		b->coorf2[0]++;
	if (b->rnd2 == 2 && i % 15 == 0
		&& b->map[b->coorf2[0]][b->coorf2[1] - 1] != '1')
	{
		b->f2d = 'l';
		b->coorf2[1]--;
	}
	if (b->rnd1 == 3 && i % 15 == 0
		&& b->map[b->coorf2[0]][b->coorf2[1] + 1] != '1')
	{
		b->f2d = 'r';
		b->coorf2[1]++;
	}
	i++;
}

void	deadb(t_box *b)
{
	if ((b->coorp[0] == b->coorf1[0] && b->coorp[1] == b->coorf1[1])
		|| (b->coorp[0] == b->coorf2[0] && b->coorp[1] == b->coorf2[1]))
	{
		b->exwait++;
	}
}

void	exit_waitb(t_box *b)
{
	if (b->exwait > 4)
		endb(b);
	if (b->exwait > 0)
		b->exwait++;
}
