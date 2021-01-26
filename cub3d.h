/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INC/cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:42:49 by aali-mou          #+#    #+#             */
/*   Updated: 2021/01/09 15:45:20 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdint.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#define BUFFER_SIZE 30
#define texturewidth 64
#define textureheight 64
#define TITLESIZE 64
#define MAP_NUMS_ROWS 10
#define MAP_NUMS_COLS 10
#define WINDOW_WIDTH (TITLESIZE * MAP_NUMS_COLS)
#define WINDOW_HEIGHT (TITLESIZE * MAP_NUMS_ROWS)
#define FOVANGLE (60 * (M_PI / 180))
#define WALLSTRIPWIDTH 1
#define NUMRAYS (WINDOW_WIDTH / WALLSTRIPWIDTH)
#define Minimapfac 0.2

int					g_tab[10][10];
void				*g_mlx_ptr;
void				*g_win_ptr;
float				g_foundvertwallhit;
float				g_foundhortwallhit;
float				g_wallhitx;
float				g_wallhity;
float				g_distance;
float				g_RAYS[10000][10000];
float				g_washithorizontal;
float				g_washitvertical;
int					*g_walltexture;

typedef struct s_player
{
	int		walkdirection;
	int		turndirection;
	float	x;
	float	y;
	float	rotationangle;
	float	movespeed;
	float	rotationspeed;
	float	wallhorhitx;
	float	wallhorhity;
	float	wallverhitx;
	float	wallverhity;
	float	nexthorx;
	float	nexthory;
	float	nextverx;
	float	nextvery;

}					t_cord;

t_cord			g_cord;

typedef struct	s_rays
{
	float	distance;
	int		washitvertical;
	int		washithorizontal;
	int		facingupdown;
	float	rayangle;
	int		facingrightleft;
	float	wallhitx;
	float	wallhity;
}					t_rays;

t_rays			*g_rays;

void				loadtexture(void);
void				textureanalyse(void);
int					key_release(int key);
int					key_press(int key);
void	 			printsquare(int i, int j, void *mlx_ptr, void *win_ptr);
void				draw_map();
void				draw_player(float x, float y);
int					move_player(void *taram);
void				draw_line(float x, float y, float j);

typedef struct	s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

t_data			img;

void				*iiimg;
char				*tp;
int					img_width;
int					img_height;
unsigned int		*data;

typedef struct	s_sprite1
{
	void				*img;
	unsigned int		*data;
	char				*file;
	int					width;
	int					height;
	int					color;
}					t_sprite;

t_sprite			spr;

typedef struct	s_texture
{
	void				*img;
	unsigned int		*data[5];
	char				*file[5];
	int					width;
	int					height;
	int					color;
}					t_texture;

t_texture		tex;
int					get_next_line(int fd, char **line);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(char *s1, size_t i);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(char *s);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_calloc(size_t count, size_t size);
char				**ft_split_whitespaces(char *str);
char				**ft_split_virgules(char *str);
void				texture(char *line);
void				floorcolor(char *line);
int					ft_atoi(const char *str);
unsigned long		creatergb(int r, int g, int b);
void				ceillingcolor(char *line);
float				newray(float ray);
void				analyse_sprite(int i);
void				loadsprite(void);

typedef struct	s_params
{
	int					g_width;
	int					g_height;
	char				*texture;
	unsigned long		Florcolor;
	unsigned long		Ceillingcolor;
	int					num_col;
	int					num_rows;
	int					tab[100][100];
	int					i;
	int					j;
	char				**s5;
	int					count;
}						t_params;

t_params			param;
int					g_count;
char				*s;
void				treatmap(char *line);
char				**ft_split(char *str, char c);
int					g_spritecount;

typedef struct	s_sprite
{
	float				x;
	float				y;
	float				xof;
	float				yof;
	float				angle;
	float				distance;
	int					width;
	int					heigth;
	unsigned int		*data;
	float				size;

}						g_param;

g_param				*g_sp;
void					function_readingmaptogivespritecount(char **line);
int						spritesize;
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
float					get_distance(float x0, float y0, float x, float y);
void					drawrect(float x, float y, float width, float heigh, int color);
int						haswallat(float x, float y);
void					draw_line2(float x, float y, float w, float z, int color);
int						rayfacingupdown(float ray);
int						rayfacingrightleft(float ray);
void					castalleays(void);
void					render3Dprojectwalls(void);
void					sprite_function(void);
void					init_sprite(void);
float					deg(float x);
void					to_sort(void);
void					to_sprite(void);
void					draw_sprite(int id);
int						linecount;
int						mapfinding;
int						virgulecount;

typedef struct		s_check
{
	int		Resolution;
	int		TextureNo;
	int		TextureSu;
	int		TextureWe;
	int		TextureEa;
	int		Sprite;
	int		Floor;
	int		Ceillig;
	int		Player;
}						c_param;

c_param				check;
typedef struct		s_render
{
	float			raydistance;
	float			distanceProjectpllane;
	float			wallstripheight;
	int				walltoppixel;
	int				wallbotpixel;
	int				Textureoffsetx;
	int				Textureoffsety;
	int				distancefromtop;
	unsigned int	Color;
	int				i;
	int				j;
}						f_param;
f_param				g_render;
char					**mapp;

void	remplirmap(char **map);
void	swappingmaps(char **map);
void	handleerroe1(void);
void	findingnumofcols(void);
void	treatmap(char *string);
void	renderhelper2(int i, int j);
void	renderhelper1(int i, int j);
void	rendring(int i);
void	render3dprojectwalls(void);
void	handleerror2(char **map);
void	find_zero_in_map(char **map);
void	resolution(char *line);
void	checkresolutionparam(int check, char **s);
void	init(void);
void	analyse(char *line);
void	read_line(void);
void	texture(char *line);
void	traitrotaionangle(char c);
void	init_param(void);
void	traitnotexture(char **s, int fd);
void	traitsotexture(char **s, int fd);
void	traitwetexture(char **s, int fd);
void	traitestexture(char **s, int fd);
void	traitspactex(char **s, int fd);
void	checkdigit(char **s, int i);
















#endif