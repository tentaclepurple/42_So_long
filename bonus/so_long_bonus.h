/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:19:52 by imontero          #+#    #+#             */
/*   Updated: 2023/07/14 12:10:20 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>
# include "mlx.h"

/* typedef struct s_b
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
	void	*foe1;
	void	*foe2;
	char	f2d;		dirección a donde mira el perrete	
	int		exwait;		variable para hacer un delay a la salida
	int		numc;		cantidad de coleccionables
	int		res;		resolucion
	int		swpl;		switch de estado mono idle/eat
	int		rnd1;
	char	**map;
	char	*str;
	char	*stps;
	int		*coorp;
	int		*coorf1;
	int		*coorf2;
}			t_box; */

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
	void	*foe1;
	void	*foe2;
	char	f2d;		
	int		exwait;
	int		numc;
	int		res;
	int		swpl;
	int		rnd1;
	int		rnd2;
	char	**map;
	char	*str;
	char	*stps;
	int		*coorp;
	int		*coorf1;
	int		*coorf2;
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
char		*ft_itoa(int n);

/* LOGIC */

void		free_matb(char **mat);
char		*map2strb(char *map);
char		**str2matrixb(char *str);

/* CHECK */

void		check_2nb(char *str);
void		check_pe_2m_ceb(char *str);
void		check_pce10nb(char *str);
void		check_rectangleb(char **mat);
void		check_perimeterb(char **mat);
int			*get_char_in_matb(char **map, char c);
int			find_char_in_matb(char **map, char c);
char		**paint_pathsb(char **mapcpy, int x, int y);
void		check_pathb(char *str);
void		check_berb(char *str);
void		check_cb(t_box *b);

/* ERROR */

void		error_2m_ceb(char *str);
void		error_no_ceb(char *str);
void		error_argcb(int argc);
void		error_invalid_strb(char *str);
void		error_invalid_matb(char **mat);
void		error_perimeterb(char **mat);
void		error_fileb(void);
void		error_pathb(void);
void		error_nameb(void);

/* GAME */

void		start_checkb(char *argum, t_box *b);
void		ft_initb(t_box *b);
void		ft_declare_imagesb(t_box *b);
void		pimages_grndb(t_box *b);
void		pimages_2b(t_box *b);
void		pimages_plb(t_box *b);
void		pimages_foesb(t_box *b);
int			lhookb(t_box *b);
int			khookb(int keycode, t_box *b);
void		movementb(t_box *b, int ni, int nj);
void		ft_foe1_movb(t_box *b);
void		ft_foe2_movb(t_box *b);
int			endb(t_box *b);
void		deadb(t_box *b);
void		exit_waitb(t_box *b);

/* ANIMATIONS */

void		ft_anim_colb(t_box *b);
void		ft_anim_plb(t_box *b);
void		ft_anim_eatb(t_box *b);
void		ft_anim_exb(t_box *b);
void		ft_anim_foe1b(t_box *b);
void		ft_anim_foe2b(t_box *b);
void		ml_img_colb(t_box *b, char *s);
void		ml_img_plb(t_box *b, char *s);
void		ml_img_exb(t_box *b, char *s);
void		ml_img_foe1b(t_box *b, char *s);
void		ml_img_foe2b(t_box *b, char *s);

#endif