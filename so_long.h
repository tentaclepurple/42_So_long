/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:19:52 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 16:09:30 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_b
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		w;
	int		h;
	void	*grnd;
	void	*wall;
	void	*ex;
	void	*col;
	void	*pl;
	int		exwait;
	int		numc;
	int		res;
	char	**map;
	char	*str;
	int		*coorp;
}			t_box;

/* AUX */

int			ft_printf(const char *s, ...);
void		*ft_calloc(size_t n, size_t size);
char		*get_next_line(int fd);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
void		free_mat(char **mat);

/* LOGIC */

void		free_mat(char **mat);
char		*map2str(char *map);
char		**str2matrix(char *str);

/* CHECK */

void		check_2n(char *str);
void		check_pe_2m_ce(char *str);
void		check_pce10n(char *str);
void		check_rectangle(char **mat);
void		check_perimeter(char **mat);
int			*get_char_in_mat(char **map, char c);
int			find_char_in_mat(char **map, char c);
char		**paint_paths(char **mapcpy, int x, int y);
void		check_path(char *str);
void		check_ber(char *str);
void		check_c(t_box *b);

/* ERROR */

void		error_2m_ce(char *str);
void		error_no_ce(char *str);
void		error_argc(int argc);
void		error_invalid_str(char *str);
void		error_invalid_mat(char **mat);
void		error_perimeter(char **mat);
void		error_file(void);
void		error_path(void);
void		error_name(void);

/* GAME */

void		start_check(char *argum, t_box *b);
void		ft_init(t_box *b);
void		ft_declare_images(t_box *b);
void		pimages_grnd(t_box *b);
void		pimages_2(t_box *b);
void		pimages_pl(t_box *b);
int			play_hook(t_box *b);
int			lhook(t_box *b);
int			khook(int keycode, t_box *b);
void		movement(t_box *b, int ni, int nj);
int			end(t_box *b);

#endif