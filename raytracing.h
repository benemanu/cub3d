#define height 480
#define width 640

typedef struct s_img
{
	void	*img;
	int		*data;
	int		img_width;
	int		img_height;
	int 	endian;
	int 	bpp;
	int 	line_len;
}				t_img;

typedef struct s_info
{
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	void	*mlx;
	void	*win;
	t_img 	img;
	int 	buff[height][width];
	double	mov_speed;
	double	rot_speed;
	int 	**texture;

}				t_info;