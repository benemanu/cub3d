/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:00:30 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:00:32 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BONUS_H
# define INPUT_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAP_INFO 1
# define UNDEFINED 2
# define COLOR 3
# define PLAYER 4
# define CHARACTER 5
# define EMPTY_LINE 6
# define WALLS 7
# define ENDING 8
# define CANNOT_OPEN 9
# define TEXTURE 10
# define ALLOCATION 99

# define CURR_P map->grid[i][j]

typedef struct s_map
{
	char			**grid;
	unsigned int	width;
	unsigned int	height;
	int				error;
	char			*north_t;
	char			*south_t;
	char			*west_t;
	char			*east_t;
	int				floor_rgb[3];
	int				ceiling_rgb[3];
	int				player_pos[2];
	char			player_dir;
}					t_map;

//error/exit/free
void				ft_free_map_struct(t_map *map);
void				ft_throw_error(t_map *map, int code);

//file
void				ft_check_file(t_map *map, char *filename);

//info
void				ft_check_and_save_info(t_map *map, char *str);
int					ft_check_texture_files(t_map *map);

//file_utils
int					ft_check_if_empty(char *str);
int					ft_is_first_line(char *str);
void				ft_free_split(char **strs);
int					ft_map_info_full(t_map *map);

//grid
void				ft_parse_grid(t_map *map);
void				ft_check_first_and_last_row(t_map *map);

//grid_utils
void				ft_print_grid(char **grid);

//raycast
void				ft_main_raycast(t_map *map);

#endif