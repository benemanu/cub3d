/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:00:42 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 19:04:27 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "input_bonus.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_Q 12
# define K_E 14
# define K_ESC 65307
# define K_SPACE 32
# define HEIGHT 720
# define WIDTH 1280
# define FOV 60

typedef struct s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			esc;
	int			space;
}				t_key;

typedef struct s_sprite
{
	int			sprite_height;
	int			sprite_width;
	int			s_bpp;
	int			x_off;
	int			y_off;
}				t_sprite;

typedef struct s_image
{
	void		*img;
	void		*data;
	int			size_l;
	int			bpp;
	int			endian;
	t_sprite	dimensions;
}				t_image;

typedef struct s_game
{
	t_image		north;
	t_image		south;
	t_image		west;
	t_image		east;
	t_image		game;
	t_image		pistol0;
	t_image		pistol1;
	t_image		pistol2;
	t_image		pistol3;
	t_image		healthbar;
	t_image		hud_pistol;
	t_image		ammo_full;
	t_image		ammo_empty;
}				t_game;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		raydirx;
	double		raydiry;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		wallx;
	double		mov_speed;
	double		rot_speed;
	double		horz_speed;
	double		step;
	double		texpos;
	int			color;
	int			texy;
	int			x;
	int			texnum;
	int			texx;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			side;
	int			hit;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
}				t_ray;

typedef struct s_info
{
	t_game		game;
	t_key		key;
	t_ray		ray;
	t_map		*map;
	void		*mlx;
	void		*win;
	int			img_width;
	int			img_height;
	int			c_col;
	int			f_col;
}				t_info;

//raycast.c
void			ft_draw(int start, int end, t_info *info);
void			ft_init_var(t_info *info);
void			ft_my_mlx_pixel_put(t_info *info, int x, int y, int color);

//load_images
void			ft_load_images(t_info *info);

//key config
int				ft_key_config(int key, t_info *info);
int				ft_key_release(int key, t_info *info);
int				ft_close_window(t_info *info);

//calculations
int				ft_main_calc(t_info *info);

//calculations_utils
void			ft_ray_init(t_info *info);
void			ft_calc_pixel(t_info *info);
int				ft_get_color(t_info *info, int ind);

//movement
void			ft_move_forth_back(t_info *info);
void			ft_move_left_right(t_info *info);
void			ft_rotate(t_info *info);

//ray_free
void			ft_ray_free(t_info *info, t_map *map);

//minimap.c
void			ft_draw_minimap(t_info *info);

//pistol
void			ft_shoot_pistol(t_info *info);
void			ft_load_img_pistol_0(t_info *info, char *img);
void			ft_load_img_pistol_1(t_info *info, char *img);
void			ft_load_img_pistol_2(t_info *info, char *img);
void			ft_load_img_pistol_3(t_info *info, char *img);

//sprite_utils.c
void			ft_draw_sprite(t_info *info, void *img_data, int size_line,
					t_sprite *sprite);

//hud
void	ft_load_img_healthbar(t_info *info, char *img);
void	ft_load_img_hud_pistol(t_info *info, char *img);
void	ft_draw_hud(t_info *info);
void	ft_load_img_ammo_full(t_info *info, char *img);
void	ft_load_img_ammo_empty(t_info *info, char *img);

//ammo
void	ft_draw_ammo(t_info *info);

#endif