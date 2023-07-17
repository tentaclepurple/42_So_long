/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:39:21 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:07:48 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_box	b;

	if (argc != 2)
		error_argc(argc);
	start_check(argv[1], &b);
	ft_init(&b);
	mlx_loop(b.mlx_ptr);
	return (0);
}
