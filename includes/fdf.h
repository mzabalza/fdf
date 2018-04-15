/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:27:20 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/20 15:40:20 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 2000
# define HEIGHT 1300

/*
**map->size		size of output window
**map->x			number of columns
**map->y			number of rows
**map->matrix	map stored in a char **variable
*/

typedef struct 		s_point
{
	float			x;
	float			y;
	float			z;
	int				i; //no lo uso
	int				j;
	float			color;

}					t_point;

typedef struct 		s_map
{
	float			radx;
	float			rady;
	float			radz;
	char			*doc;
	void 			*mlx_ptr;
	void 			*win_ptr;
	int				fd;
	int				scal;
	void			*image;
	int				*img_str;
	int				line_size;
	// punto inicial
	int				tx;
	int				ty;
	// distancia entre puntos
	int				lxy;
	//altura
	float				height;
	
	int				p1[2];
	int				p2[2];
	int				nb_col;
	int				nb_row;
	int				**matrix;
	t_point			**p_matrix;
	int				z_range[2];

}					t_map;


int 				main(int ac, char **av);
void				show_map(t_map *map);
void				show_p_matrix(t_map *map, t_point **p_matrix);
int					create_points(t_map *map);
int					ft_error(char *str, int rtn_value);
int					ft_parser(t_map *map);
int					get_next_line(const int fd, char **line);
void				ft_new_matrix(t_map *map, t_point **p_matrix);
/*
**----------GEOMETRIC TRANSFORMATIONS-------------------------------
*/

void		rotate_y(float *x, float *z, float rad);
void		rotate_x(float *y, float *z, float rad);
void		rotate_z(float *x, float *y, float rad);
/*
**----------GEOMETRIC TRANSFORMATIONS-------------------------------
*/
void		draw_points(t_map *map, t_point **p_matrix);
void		draw_xlines(t_map *map, t_point **p_matrix);
void		draw_ylines(t_map *map, t_point **p_matrix);
/*
**----------EVENT MANAGEMENT-------------------------------
*/
void		fill_img_str(int *img_str, int x, int y, int color);
void	clear_img_str(t_map *map);
/*
**----------EVENT MANAGEMENT-------------------------------
*/
int			deal_key(int key, void *param);
/*
**----------EVENT MANAGEMENT-------------------------------
*/
float	select_color(t_map *map, int z);
float	color_gradient(t_point p1, t_point p2, float dx, float dy);

#endif
