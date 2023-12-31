/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:15:19 by sisen             #+#    #+#             */
/*   Updated: 2023/08/17 15:38:40 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	make_ready(t_win *win)
{
	image_on_window(win);
	where_is_char('C', win);
	where_is_char('E', win);
	where_is_char('P', win);
}

int	main(int ac, char **av)
{
	t_win	*win;
	char	*map;

	if (ac != 2)
		show_error(8);
	map = av[1];
	ber_error(map);
	win = malloc(sizeof(t_win));
	add_malloc(win);
	win->mlx = mlx_init();
	not_fd(map, win);
	win->mlx_win = mlx_new_window(win->mlx, win->map->wid * 64,
			win->map->hei * 64, "so_long");
	make_ready(win);
	map_control(map_error(win->map->wid, win->map->hei,
			copy_map(map)));
	wall_error(win);
	mlx_hook(win->mlx_win, 2, 1L << 0, move_char, win);
	mlx_hook(win->mlx_win, 17, 0, ft_exit, win);
	mlx_loop(win->mlx);
	free_copy(win);
	return (0);
}
