/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:05:45 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:26:49 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	end(t_box *b)
{
	free(b->str);
	free(b->coorp);
	mlx_destroy_window(b->mlx_ptr, b->win_ptr);
	free_mat(b->map);
	exit(-1);
	return (0);
}

void	check_c(t_box *b)
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
