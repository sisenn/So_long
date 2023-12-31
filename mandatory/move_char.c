/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:15:08 by sisen             #+#    #+#             */
/*   Updated: 2023/08/15 03:48:24 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei - 1][win->map->wid] != '1')
		{
			if (win->map->map[win->map->hei - 1][win->map->wid] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei - 1][win->map->wid] = 'P';
				total_steps();
				ft_putstr_fd("You Win!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei - 1][win->map->wid] != 'E')
			{
				total_steps();
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei - 1][win->map->wid] = 'P';
				win->map->hei -= 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_down(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei + 1][win->map->wid] != '1')
		{
			if (win->map->map[win->map->hei + 1][win->map->wid] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei + 1][win->map->wid] = 'P';
				total_steps();
				ft_putstr_fd("You Win!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei + 1][win->map->wid] != 'E')
			{
				total_steps();
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei + 1][win->map->wid] = 'P';
				win->map->hei += 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_right(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei][win->map->wid + 1] != '1')
		{
			if (win->map->map[win->map->hei][win->map->wid + 1] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei][win->map->wid + 1] = 'P';
				total_steps();
				ft_putstr_fd("You Win!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei][win->map->wid + 1] != 'E')
			{
				which_image('P', win);
				total_steps();
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei][win->map->wid + 1] = 'P';
				win->map->wid += 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_left(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei][win->map->wid - 1] != '1')
		{
			if (win->map->map[win->map->hei][win->map->wid - 1] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei][win->map->wid - 1] = 'P';
				total_steps();
				ft_putstr_fd("You Win!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei][win->map->wid - 1] != 'E')
			{
				total_steps();
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei][win->map->wid - 1] = 'P';
				win->map->wid -= 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

int	move_char(int keycode, t_win *win)
{
	if (keycode == 13)
		move_up (win);
	if (keycode == 1)
		move_down (win);
	if (keycode == 0)
		move_left (win);
	if (keycode == 2)
		move_right (win);
	if (keycode == 53)
		ft_exit(win);
	return (0);
}
