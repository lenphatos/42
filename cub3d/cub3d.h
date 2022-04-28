/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:01:03 by simoulin          #+#    #+#             */
/*   Updated: 2020/02/18 15:54:27 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# define PI 3.14159265359
# define RAD 0.01745329251
# define DEPL 1
# define ANGLE 1
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

typedef struct	s_data
{
	int				dev;
	int				*texture[5];
	int				key[280];
	int				*addr;
	int				color1;
	void			*mlx_img;
	void			*img_sprite;
	void			*img_north;
	void			*img_south;
	void			*img_east;
	void			*img_weast;
	void			*mlx_new_img;
	void			*mlx_ptr;
	void			*mlx_win;
	char			**tab;
	char			**map;
	char			**folder;
	char			*path[9];
	int				count;
	int				maxx;
	float			angle;
	float			deviation;
	float			distplayer;
	int				height;
	int				width;
	int				hh[5];
	int				ww[5];
	float			posx;
	float			posy;
	float			t_posx;
	float			t_posy;
	float			hm;
	float			hauteursprite;
	float			ya;
	float			xa;
	float			y;
	float			x;
	int				color;
	char			*sprite;
	char			*north;
	char			*south;
	char			*weast;
	char			*east;
	int				value_one_s;
	int				value_two_s;
	int				detect_sprite;
	int				h;
	int				q[5];
	int				l;
	int				error;
	int				bpp;
	int				endian;
	int				sl;
	int				count_txt;
	int				cheror[5];
	int				floor;
	int				sky;
	float			distance_h;
	float			distance_v;
	float			hs;
	float			dist_sprite_h;
	float			dist_sprite_v;
	float			dist_sprite;
	float			hhh;
	float			lll;
	int				test[5];
	int				check_reso;
	int				speed;
	int				i;
	float			xx;
	float			yy;
	int				index;
}				t_data;

int				ft_recup_map(char *str);
int				ft_locate(t_data *data);
int				ft_check_cub(char *str);
int				ft_print_img(t_data *data);
int				save_bmp(t_data *data);
int				ft_count_t(char *str);
int				ft_atoi(const char *str);
int				ft_texture(t_data *data);
int				ft_decaler(t_data *data);
int				ft_count_one(t_data *data);
int				ft_check_map(t_data *data);
int				ft_strlen(const char *str);
int				ft_resolution(t_data *data);
int				ft_size_array(char **data);
int				ft_strcmp(char *s1, char *s2);
int				ft_resolution(t_data *data);
int				ft_take_texture(t_data *data);
int				ft_check_texture(t_data *data);
int				ft_cut_space_map(t_data *data);
int				ft_verif_char_map(t_data *data);
int				ft_number_element(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
int				ft_texte_floor_sky(t_data *data, int i);
int				ft_print(char **str, int fd, char *buf);
int				get_next_line(const int fd, char **line);
int				check_bmp(int ac, char **av, t_data *data);
int				ft_regul(t_data *data, char **av, int ac);
int				ft_parsing(t_data *data, char **av, int ac);
int				clickescape(t_data *data);
int				ft_size(t_data *data);
int				ft_map_verif(char c);
void			ft_free(t_data *data);
void			ft_putstr(char *str);
void			ft_test(t_data *data);
void			ft_cub3d(t_data *data);
void			ft_sprite_h(t_data *data);
void			ft_sprite_v(t_data *data);
void			ft_where_iam_h(t_data *data);
void			ft_where_iam_v(t_data *data);
void			ft_viseur(t_data *data, float x, float y);
void			ft_print_wall(t_data *data, float x, float y);
void			ft_print_sprite_h(t_data *data, float x, float y);
void			ft_print_wall_sprite(t_data *data, float x, float y);
char			*ft_path_sprite(char *str);
char			*ft_path_north(char *str);
char			*ft_path_south(char *str);
char			*ft_path_east(char *str);
char			*ft_path_weast(char *str);
char			*ft_strdup(const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strndup(const char *s, size_t n);
char			*ft_take_path(char *str);
char			*ft_nospace_m(char *str, int lenmax);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
float			ft_horizontal(t_data *data);
float			ft_vertical(t_data *data);

#endif
