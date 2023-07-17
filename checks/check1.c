/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:10:19 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:07:11 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 
	checkea si el perimetro de la matriz es pared ('1')
 */
void	check_perimeter(char **mat)
{
	int	i;
	int	len;

	i = 0;
	len = -1;
	while (mat[i])
	{
		if (mat[i][0] != '1' || mat[i][ft_strlen(mat[i]) - 1] != '1')
			error_perimeter(mat);
		i++;
		len++;
	}
	i = 0;
	while (mat[0][i])
	{
		if (mat[0][i] != '1' || mat[len][i] != '1')
			error_perimeter(mat);
		i++;
	}
}

/*
	checkea si la matriz es rectangulo/cuadrado
	comprueba que todas las filas midan lo mismo
*/
void	check_rectangle(char **mat)
{
	int	i;

	i = 1;
	while (mat[i])
	{
		if (ft_strlen(mat[i]) != ft_strlen(mat[i - 1]))
			error_invalid_mat(mat);
		i++;
	}
	i = 0;
	while (mat[i])
		i++;
	if (i < 3 || ft_strlen(mat[1]) < 3)
		error_invalid_mat(mat);
}

/*
	checkea 2 \n seguidos
*/
void	check_2n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '\n' || (str[i] == '\n' && str[i + 1] == '\n'))
			error_invalid_str(str);
		i++;
	}
}

/* 
	comprueba si hay algun caracter no valido
*/
void	check_pce10n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'E' && str[i] != 'C' && str[i] != '1'
			&& str[i] != '0' && str[i] != '\n' && str[i] != '\r')
			error_invalid_str(str);
		i++;
	}
}

/*
	comprobar si hay 1 P, 1E y al menos 1C
	count[0] = indice
	count[1] = contador para P
	count[2] = contador para E
*/
void	check_pe_2m_ce(char *str)
{
	int	count[3];

	if (!(ft_strchr(str, 'P')) || !(ft_strchr(str, 'E'))
		|| !(ft_strchr(str, 'C')))
		error_no_ce(str);
	count[0] = -1;
	count[1] = 0;
	count[2] = 0;
	while (str[++count[0]] != '\0')
	{
		if (str[count[0]] == 'P')
			count[1]++;
		else if (str[count[0]] == 'E')
			count[2]++;
	}
	if (count[1] > 1 || count[2] > 1)
		error_2m_ce(str);
}
