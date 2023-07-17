/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:10:19 by imontero          #+#    #+#             */
/*   Updated: 2023/07/11 10:17:46 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 
	obtenemos las coordenadas de un determinado char que le pasamos.
	devuelve un arraf con las coordenadas (coor[c], coor[f])
 */
int	*get_char_in_mat(char **map, char a)
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
char	**paint_paths(char **mapcpy, int f, int c)
{
	if (mapcpy[f][c] == '1' || mapcpy[f][c] == 'c')
		return (0);
	if (mapcpy[f][c] == 'E')
		mapcpy[f][c] = 'c';
	if (mapcpy[f][c] == 'C')
		mapcpy[f][c] = 'c';
	if (mapcpy[f][c] == '0')
		mapcpy[f][c] = 'c';
	paint_paths(mapcpy, f - 1, c);
	paint_paths(mapcpy, f, c - 1);
	paint_paths(mapcpy, f + 1, c);
	paint_paths(mapcpy, f, c + 1);
	return (0);
}

/* 
	Checkea caminos invalidos:
	Pinta el mapa f busca 'C' f 'E'.
	Si los encuentra es que no ha podido llegar a ellos.
 */
void	check_path(char *str)
{
	int		*coor;
	char	**matcpy;

	matcpy = str2matrix(str);
	coor = get_char_in_mat(matcpy, 'P');
	paint_paths(matcpy, coor[0], coor[1]);
	if (find_char_in_mat(matcpy, 'C') == 0 \
		&& find_char_in_mat(matcpy, 'E') == 0)
	{
		free(coor);
		free_mat(matcpy);
		return ;
	}
	free(coor);
	free_mat(matcpy);
	error_path();
}

void	check_ber(char *str)
{
	if (ft_strlen(str) < 5 || str[ft_strlen(str) - 5] == '/')
		error_file();
	if (str[ft_strlen(str) - 1] != 'r')
		error_file();
	if (str[ft_strlen(str) - 2] != 'e')
		error_file();
	if (str[ft_strlen(str) - 3] != 'b')
		error_file();
	if (str[ft_strlen(str) - 4] != '.')
		error_file();
}

/* checks iniciales */
void	start_check(char *argum, t_box *b)
{
	check_ber(argum);
	b->str = map2str(argum);
	check_c(b);
	check_2n(b->str);
	check_pce10n(b->str);
	check_pe_2m_ce(b->str);
	b->map = str2matrix(b->str);
	check_rectangle(b->map);
	check_perimeter(b->map);
	check_path(b->str);
	b->coorp = get_char_in_mat(b->map, 'P');
}
