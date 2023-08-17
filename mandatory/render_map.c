/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:15:14 by sisen             #+#    #+#             */
/*   Updated: 2023/08/15 03:48:03 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	current_map(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map->map[y] != NULL)
	{
		while (win->map->map[y][x] && win->map->map[y][x] != '\n')
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, \
			which_image(win->map->map[y][x], win), x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
}

int	open_exit(t_win *win)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (win->map->map[y] != NULL)
	{
		while (win->map->map[y][x])
		{
			if (win->map->map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
		x = 0;
	}
	if (i == 0)
		return (1);
	return (0);
}

void	total_steps(void)
{
	static int	i;

	i++;
	ft_putstr_fd("total steps : ", 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_exit(t_win *win)
{
	(void) win;
	ft_putstr_fd("Game Closed\n", 1);
	exit(1);
	return (1);
}
