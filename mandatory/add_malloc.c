/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisen <sisen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:14:39 by sisen             #+#    #+#             */
/*   Updated: 2023/08/15 03:14:41 by sisen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_malloc(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	win->image = malloc(sizeof(t_data));
	win->map->map = (char **)malloc(sizeof(char *) * 128);
}

void	free_copy(t_win *check)
{
	free(check->map->map);
	free(check->map);
	free(check->image);
	free(check);
}
