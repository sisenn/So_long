/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:10:39 by sisen             #+#    #+#             */
/*   Updated: 2023/08/15 03:10:42 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../../minilibx_opengl_20191021/mlx.h"
# include "get_next_line_bonus.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	int		img_wid;
	int		img_hei;
	void	*wall;
	void	*bg;
	void	*player;
	void	*coin;
	void	*exit;
}	t_data;

typedef struct s_map
{
	void	*map_adress;
	char	**map;
	int		wid;
	int		hei;
	int		ex;
	int		countedc;
}	t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_data	*image;
}	t_win;

void	*which_image(char c, t_win *win);
void	map_images(t_win *win);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	show_error(int err);
void	map_wid_hei(int fd, t_win *win);
void	image_on_window(t_win *win);
int		move_char(int keycode, t_win *win);
void	add_malloc(t_win *win);
void	where_is_char(char c, t_win *win);
void	wall_error(t_win *win);
void	wall_error2(int x, int y, t_win *win);
void	ber_error(char *map);
t_win	*map_error(int wid, int hei, t_win *check);
t_win	*copy_map(char *map);
void	current_map(t_win *win);
void	move_up(t_win *win);
void	move_down(t_win *win);
void	move_right(t_win *win);
void	move_left(t_win *win);
void	char_error(int piece, char c);
int		open_exit(t_win *win);
void	total_steps(t_win *win);
void	map_control(t_win *check);
void	free_copy(t_win *check);
void	not_fd(char *map, t_win *win);
char	*ft_itoa(int n);
int		ft_exit(t_win *win);
#endif