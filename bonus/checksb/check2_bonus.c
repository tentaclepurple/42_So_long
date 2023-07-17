/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:10:19 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 10:50:00 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/* 
	obtenemos las coordenadas de un determinado char que le pasamos.
	devuelve un arraf con las coordenadas (coor[c], coor[f])
 */
int	*get_char_in_matb(char **map, char a)
{
	int	f;
	int	c;
	int	*coor;

	c = 0;
	f = 0;
	coor = malloc(sizeof(int) * 2);
	while (map[f])
	{
		c = 0;
		while (map[f][c])
		{
			if (map[f][c] == a)
			{
				coor[0] = f;
				coor[1] = c;
				return (coor);
			}
			c++;
		}
		f++;
	}
	return (NULL);
}

/* 
	recorre el mapa f va "pintando" camino recorrido cambiando los tiles:
	cambia '0' por 'c'
	cambia 'E' por 'e'
	cambia 'C' por 'c'
	si no puede llegar a 'E' o 'C', el mapa acabará sin 'e' o 'c' f sabremos
	que no hay camino posible
 */
char	**paint_pathsb(char **mapcpy, int f, int c)
{
	if (mapcpy[f][c] == '1' || mapcpy[f][c] == 'c' || mapcpy[f][c] == 'F' ||
		mapcpy[f][c] == 'f')
		return (0);
	if (mapcpy[f][c] == 'E' || mapcpy[f][c] == 'C' || mapcpy[f][c] == '0')
		mapcpy[f][c] = 'c';
	paint_pathsb(mapcpy, f - 1, c);
	paint_pathsb(mapcpy, f, c - 1);
	paint_pathsb(mapcpy, f + 1, c);
	paint_pathsb(mapcpy, f, c + 1);
	return (0);
}

/* 
	Checkea caminos invalidos:
	Pinta el mapa f busca 'C' f 'E'.
	Si los encuentra es que no ha podido llegar a ellos.
 */
void	check_pathb(char *str)
{
	int		*coor;
	char	**matcpy;

	matcpy = str2matrixb(str);
	coor = get_char_in_matb(matcpy, 'P');
	paint_pathsb(matcpy, coor[0], coor[1]);
	if (find_char_in_matb(matcpy, 'C') == 0 \
		&& find_char_in_matb(matcpy, 'E') == 0)
	{
		free(coor);
		free_matb(matcpy);
		return ;
	}
	free(coor);
	free_matb(matcpy);
	error_pathb();
}

void	check_berb(char *str)
{
	if (ft_strlen(str) < 5 || str[ft_strlen(str) - 5] == '/')
		error_fileb();
	if (str[ft_strlen(str) - 1] != 'r')
		error_fileb();
	if (str[ft_strlen(str) - 2] != 'e')
		error_fileb();
	if (str[ft_strlen(str) - 3] != 'b')
		error_fileb();
	if (str[ft_strlen(str) - 4] != '.')
		error_fileb();
}

/* checks iniciales */
void	start_checkb(char *argum, t_box *b)
{
	check_berb(argum);
	b->str = map2strb(argum);
	check_cb(b);
	check_2nb(b->str);
	check_pce10nb(b->str);
	check_pe_2m_ceb(b->str);
	b->map = str2matrixb(b->str);
	check_rectangleb(b->map);
	check_perimeterb(b->map);
	check_pathb(b->str);
	b->coorp = get_char_in_matb(b->map, 'P');
	b->coorf1 = get_char_in_matb(b->map, 'F');
	b->coorf2 = get_char_in_matb(b->map, 'f');
}
