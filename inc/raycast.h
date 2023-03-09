#ifndef RAYCAST_H
#define RAYCAST_H

# include  "../inc/input.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define M_PI 				3.14159265358979323846
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_Q 12
# define K_E 14
# define K_ESC 65307
# define HEIGHT 720
# define WIDTH 1280
# define FOV 60

// typedef struct s_map t_map;

typedef struct s_key
{
	int w;
	int a;
	int s;
	int d;
	int left;
	int right;
	int esc;
}               t_key;

typedef struct	s_image
{
	void	*img;
	void	*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_image;

typedef struct	s_game
{
	t_image	north;
	t_image	south;
	t_image	west; 
	t_image	east;
	t_image game;
}				t_game;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	raydirx;
	double	raydiry;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double 	camerax;
	double 	sidedistx;
	double 	sidedisty;
	double 	deltadistx;
	double 	deltadisty;
	double 	perpwalldist;
	double 	wallx;
	double	mov_speed;
	double	rot_speed;
	double  horz_speed;
	double 	step;
	double 	texpos;
	int		texy;
	int		x;
	int 	texnum;
	int 	texX;
	int 	lineheight;
	int 	drawstart;
	int 	drawend;
	int 	side;
	int 	hit;
	int 	mapx;
	int 	mapy;
	int		stepx;
	int		stepy;
}			t_ray;

typedef struct s_info
{
	t_game 	game;
	t_key	key;
	t_ray 	ray;
	t_map	*map;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		c_col;
	int		f_col;
}				t_info;

//raycast.c
int		image_loop(t_info *info);
void	draw(int start, int end, t_info *info);
void    init_var(t_info *info);
void 	my_mlx_pixel_put(t_info *info, int x, int y, int color);
void 	init2(t_info *info);

//load_img.c
void    load_images(t_info *info);
void    load_img_north(t_info *info, char *path);
void    load_img_south(t_info *info, char *path);
void    load_img_west(t_info *info, char *path);
void    load_img_east(t_info *info, char *path);

//key config
int		key_config(int key, t_info *info);
int     key_release(int key, t_info *info);
int     close_window(t_info *info);

//calculations
void    get_direction(t_info *info);
int 	main_calc(t_info *info);
void 	drawing (t_info *info);
void 	calc_dist(t_info *info);
void 	get_side(t_info *info);

//calculations_utils
void	ray_init1(t_info *info);
void    ray_init(t_info *info);

//movement
void 	move_forth_back(t_info *info);
void 	move_left_right(t_info *info);
void 	rotate(t_info *info);

//ray_free.c
void	ray_free(t_info *info, t_map *map);
void	free_images(t_info *info);


#endif