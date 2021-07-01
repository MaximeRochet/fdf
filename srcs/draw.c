/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:42:11 by mrochet           #+#    #+#             */
/*   Updated: 2021/06/30 17:38:56 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void bresenham(double x1, double y1, t_data *data)
{
	long long int z;
	long long int z1;

	printf(" x = %d x1 = %d y = %d y1 = %d \n", (int)data->x, (int)x1, (int)data->y, (int)y1);

	z = data->array[(int)data->y][(int)data->x];
	z1 = data->array[(int)y1][(int)x1];
}

void draw(t_data *data)
{
	double t_x;
	double t_y;
 
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			t_x = data->x;
			t_y = data->y;
			if(data->x < data->width - 1)
				bresenham(data->x + 1, data->y, data);
			data->x = t_x;
			data->y = t_y;
			if(data->y < data->height - 1)
				bresenham(data->x, data->y + 1, data);
			data->x = t_x;
			data->y = t_y;
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 0, 0);
}
