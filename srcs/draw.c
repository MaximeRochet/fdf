/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:42:11 by mrochet           #+#    #+#             */
/*   Updated: 2021/07/03 18:38:18 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	mod(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calc(t_data *data, double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
	*x *= 20;
	*y *= 20;
	*x += 1250;
	*y += 600;
}

void	bresenham(double x1, double y1, t_data *data)
{
	long long int	z;
	long long int	z1;

	z = data->array[(int)data->y][(int)data->x];
	z1 = data->array[(int)y1][(int)x1];
	data->color = 0xFFFFFF;
	if (z || z1)
		data->color = 0xFF0000 + z * 0x00FFFF + z * 0x0000FF;
	calc(data, &data->x, &data->y, z);
	calc(data, &x1, &y1, z1);
	z1 = max(mod(x1 - data->x), mod(y1 - data->y));
	data->x -= data->width / 2.0;
	data->y -= data->height / 2.0;
	x1 -= data->width / 2.0;
	y1 -= data->height / 2.0;
	while ((int)(data->x - x1) || (int)(data->y - y1))
	{
		if ((int)data->x < data->image.line_length && (int)data->x >= 0 && \
				(int)data->y < data->ywin && (int)data->y >= 0)
			data->image.addr[(int)(((int)data->y * data->image.line_length) \
					+ (int)data->x)] = (data->color);
		data->x += (x1 - data->x) / z1;
		data->y += (y1 - data->y) / z1;
	}
}

void	draw(t_data *d)
{
	double	t_x;
	double	t_y;

	d->y = 0;
	while (d->y < d->height)
	{
		d->x = 0;
		while (d->x < d->width)
		{
			t_x = d->x;
			t_y = d->y;
			if (d->x < d->width - 1)
				bresenham(d->x + 1, d->y, d);
			d->x = t_x;
			d->y = t_y;
			if (d->y < d->height - 1)
				bresenham(d->x, d->y + 1, d);
			d->x = t_x;
			d->y = t_y;
			d->x++;
		}
		d->y++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->image.img, 0, 0);
}
