#ifndef RAYCAST_H
#define RAYCAST_H

# ifndef CEILING_COLOR
# define CEILING_COLOR 0xADD8E6
# endif

# ifndef FLOOR_COLOR
# define FLOOR_COLOR 0xA52A2A
# endif

#ifndef height 
#define height 480
#endif

#ifndef width
#define width 640
#endif

#define M_PI 				3.14159265358979323846
# define X_EVENT_KEY_PRESS  5
# define X_EVENT_KEY_EXIT   17
# define K_W 3
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124
# define K_Q 12
# define K_E 14
# define K_ESC 53

#include "cub3D.h"

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
	int 	buff[64][64];
}				t_image;

typedef struct	s_game
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_image game;

}				t_game;

typedef struct s_info
{
	t_game 	game;
	t_key	key;
	void 	*image;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double 	raydirx;
	double	raydiry;
	double	planex;
	double	planey;
	int 	side;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		buff[height][width];
	double	mov_speed;
	double	rot_speed;
	int		**texture;
	int 	hit;

}				t_info;

int    	image_loop(t_info *info);
void    draw(t_info *info);
void    main_raycast(void);
void    load_images(t_info *info);
void    init_var(t_info *info);
void 	my_mlx_pixel_put(t_info *info, int x, int y, int color);

double 	get_player_facing_angle(t_info *info);

//loading xpm files to images
void    load_img_north(t_info *info, char *path);
void    load_img_south(t_info *info, char *path);
void    load_img_west(t_info *info, char *path);
void    load_img_east(t_info *info, char *path);

//key config
int    key_config(int key, t_info *info);

//our free
void 	our_exit(int code);


#endif