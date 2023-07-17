/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:23:46 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 10:57:16 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_matb(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

	/*
		gnl para leer y pasar todo el mapa a un string.
	*/
char	*map2strb(char *map)
{
	int		fd;
	char	*text;
	char	*temp;
	char	*gnl;

	fd = open(map, O_RDONLY);
	if (fd < 3)
		error_fileb();
	gnl = get_next_line(fd);
	text = ft_calloc(1, 1);
	while (gnl)
	{
		temp = ft_strdup(text);
		free(text);
		text = ft_strjoin(temp, gnl);
		free(temp);
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
	return (text);
}

	/*
		split para pasar string a matriz
	*/
char	**str2matrixb(char *str)
{
	char	**mat;

	mat = ft_split(str, '\n');
	return (mat);
}
