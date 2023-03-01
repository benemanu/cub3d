#ifndef RAYCAST_H
#define RAYCAST_H

#define height 600
#define width 1000
#define M_PI 3.14159265358979323846

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

}				t_game;

typedef struct s_info
{
	t_game 	game;
	void 	*image;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
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

void    image_loop(t_info *info);
void    draw(t_info *info);
void    main_raycast(void);
void    load_img(t_info *info);
void    init_var(t_info *info);
void    load_images_xpm(t_info *info, int *texture, char *path);
double get_player_facing_angle(t_info *info);


#endif