/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:54:06 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:04 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/* 
	SOLO comprueba si existe char a en la matriz
 */
int	find_char_in_matb(char **map, char a)
{
	int	f;
	int	c;

	c = 0;
	f = 0;
	while (map[f])
	{
		c = 0;
		while (map[f][c])
		{
			if (map[f][c] == a)
			{
				return (1);
			}
			c++;
		}
		f++;
	}
	return (0);
}
