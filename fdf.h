/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 19:05:56 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct	s_calc {
	double	th;
	double	ratio;
	int		width;
	int		height;
	int		size;
	int		cx;
	int		cy;
	int		len;
	int		dep;
	int		dgm;
	int		dgy;
	int		dgx;
}				t_calc;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;

typedef struct	s_dir {
	int	x;
	int	y;
}				t_dir;

typedef struct	s_line {
	int		x1;
	int		y1;
	int		size;
	int		x2;
	int		y2;
	double	radius;
}				t_line;

typedef struct	s_dotfile {
	int					dot;
	double				x;
	double				y;
	struct s_dotfile	*next;
	struct s_dotfile	*down;
}				t_dotfile;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_dotfile	*file;
	t_data		*img;
	t_calc		calc;
	int			fd;
}				t_vars;

void		my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			get_b(int trgb);
int			get_g(int trgb);
int			get_r(int trgb);
int			get_t(int trgb);
int			close_win(int keycode, t_vars *vars);
int			close_win2(t_vars *vars);
void		my_mlx_line_put(t_vars *vars, t_dir start, t_dir end, int size1, int size2);
void		my_mlx_line_put2(t_vars *vars, t_line line, t_line line2);
double		findradius(t_line line);
t_dir		makeadot(int x, int y);
t_line		combinetwodots(t_dir start, t_dir end);
int			count_list_length(t_dotfile	*lst);
int			count_list_depth(t_dotfile	*lst);
t_dotfile	*find_next_last(t_dotfile	*lst);
t_dotfile	*find_down_last(t_dotfile	*lst);
t_dotfile	*makenode(int dot);
void		readdotfile(t_dotfile **file, int fd);
void		makedotlist(t_dotfile **file, char **splited);
void		combinetwolist(t_dotfile **lst1, t_dotfile *lst2);
void		put_coords(t_dotfile **file, t_calc ca);
void		put_calcs(t_calc *calc);
void		rotatelistmid(t_vars *vars);
void		drawfilelines(t_vars *vars, int lock);
void		rotatelisty(t_vars *vars);
void		choose_rotate(t_dotfile **file, int rotatecode);
void		changecolor(t_line *line, t_line *line2, double *cor);
int			findcolor(int size, double *cor);
void		print_loop(t_vars *vars);
void		next_dot_node(t_dotfile **findow, t_dotfile **finex);
void		rotate_all(t_vars *vars);
int			find_line2(int x1, int x2, int yes, int no);
int			tcolor(double colour);
int			checkdot(int dot, int ck);
int			makecorratio(double cor, double cor2);
void		free_vars(t_vars **vars);
void		free_file(t_dotfile **file);
void		free_splited(char **splited);
void		makeimg(t_vars **vars, t_data *img);
void		findkey(t_vars *vars, int keycode);

#endif