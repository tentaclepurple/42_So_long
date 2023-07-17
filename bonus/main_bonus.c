/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:39:21 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 11:47:50 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_box	b;

	if (argc != 2)
		error_argcb(argc);
	start_checkb(argv[1], &b);
	ft_initb(&b);
	mlx_loop(b.mlx_ptr);
	return (0);
}
