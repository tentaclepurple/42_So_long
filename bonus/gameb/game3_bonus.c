/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:05:45 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 11:47:27 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	endb(t_box *b)
{
	free(b->str);
	free(b->coorp);
	free(b->coorf1);
	free(b->coorf2);
	free(b->stps);
	mlx_destroy_window(b->mlx_ptr, b->win_ptr);
	free_matb(b->map);
	exit(-1);
	return (0);
}

void	check_cb(t_box *b)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (b->str[i])
	{
		if (b->str[i] == 'C')
			c++;
		i++;
	}
	b->numc = c;
}
