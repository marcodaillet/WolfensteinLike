/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:03:43 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/24 10:39:35 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <error.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>  
# include <math.h>

# define SUCCESS 0
# define ERROR 1
# define BUFF_SIZE 4096
# define PI 3.1415926535
# define FRONT 119
# define BACK 115
# define LEFT 97
# define RIGHT 100
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363

typedef struct	s_check
{
	int			params[6];
	int			player;
}	t_check;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		offset;
	int		mini;
	void	*img2;
	void	*addr2;
	int		width;
	int		height;
}	t_data;

typedef struct	s_tex
{
	int		dir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}	t_tex;

typedef struct	s_ray
{
	double	dirx;
	double	diry;
	double	viewx;
	double	viewy;
	double	raydirx;
	double	raydiry;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	speed;
	double	turn_speed;
	double	posx;
	double	posy;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lheight;
	int		dstart;
	int		dend;
	int		x;
	int		tex;
}	t_ray;

typedef struct	s_mov
{
	int		front;
	int		back;
	int		left;
	int		right;
	int		r_left;
	int		r_right;
}	t_mov;

typedef struct  s_info
{
	char	direction;
	int		dx;
	int		dy;
	int		rx;
	int		ry;
	char	**map;
	int		F[3];
	int		C[3];
	int		f;
	int		c;
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	int		max_length;
	int		nb_lines;
	int		side;
	t_data	img;
	t_data	t[5];
	t_ray	ray;
	t_mov	mov;
	t_tex	tex;
} t_info;

// ############ CHECKER ##############

int		ft_treat_walls(char *line);
int		ft_treat_fc(char *line);
int		ft_check_map(const char *filename, t_check *check);
void	ft_last(char **last, char *s);
int		ft_start(char *s);
int		ft_wrong_char(char *s);
int		ft_check_content(char *line, char *last, t_check *check);
int		ft_check_exter(char	*s);
int		ft_not_empty(char *s);
int		ft_check_player(t_check *check);
int		ft_player(char *line);
int		ft_check_file(char *filename, t_check *check);
int		ft_check_ids(t_check *check, char *filename);
int		ft_check_walls(char *s);
int		ft_wrong_char2(char *s);

// ############ PARSING ##############

void	ft_parse_FC(char *line, t_info *info);
void	ft_parse_EA(char *line, t_info *info);
void	ft_parse_WE(char *line, t_info *info);
void	ft_parse_SO(char *line, t_info *info);
void	ft_parse_NO(char *line, t_info *info);
void	ft_parse(t_info *info, char *filename);
void	ft_init(t_info *info);
void    ft_init_mlx(t_info *info);
void    ft_init_ray(t_info *info);
void	ft_init_dir(t_info *info);

// ############ EXECUTE ##############

void	ft_ray(t_info *info);
void	ft_cub3d(t_info *info);
int		ft_key_hook(int keycode, t_info *info);
int		ft_draw_map(t_info *info);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_wall_textures(t_info *info);
void	ft_wall_addr(t_info *info);
void	ft_cub3d(t_info *info);
void	ft_mov1(t_info *info);
void	ft_mov2(t_info *info);
void	ft_mov3(t_info *info);
int		ft_press(int keycode, t_info *info);
int		ft_release(int keycode, t_info *info);
void    ft_draw(t_info *info);
void    ft_pxl_columns(t_info *info);
void    ft_rotate(t_info *info);

// ############  UTILS  ##############

void    ft_bun(void *s, size_t n);
void    ft_free(void *s);
void    ft_freen(char **s, int n);
void    ft_free_all(t_info *info);
void	ft_error(t_info *info, char *str);
int		ft_exit(t_info *info);
int		ft_error2(char *str);
int		ft_startw(const char *str, const char *pattern);
int		ft_endw(const char *str, const char *pattern);
int		ft_strlen2(char **av);
int		ft_is_map(char *line);
void    ft_bun(void *s, size_t n);
void	ft_colors(t_info *info);

#endif
