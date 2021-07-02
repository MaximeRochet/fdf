/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:03:51 by mrochet           #+#    #+#             */
/*   Updated: 2021/07/02 16:13:09 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//creer fonction free
//creer fonction error

int	ft_close(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->image.img);
	while (data->array[i])
		free(data->array[i++]);
	free(data->array[i]);
	free(data->array);
	free(data);
	exit (0);
}

int	deal_key(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	return (0);
}

void init_struct(t_data *data)
{
	data->xwin = 2500;
	data->ywin = 1200;
}

int main(int ac, char **av)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if(ac != 2)
		exit(0);

	data->array = (int **)create_array(ac, av, data);
	data->mlx_ptr = mlx_init();
	init_struct(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->xwin, data->ywin, \
			"fdf");
	data->image.img = mlx_new_image(data->mlx_ptr, data->xwin, data->ywin);
	data->image.addr = (unsigned int *)mlx_get_data_addr(data->image.img, \
			&data->image.bits_per_pixel, &data->image.line_length, \
			&data->image.endian);
	data->image.line_length /= 4;
	//data->shiftx = data->image.line_length / 2;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	mlx_loop(data->mlx_ptr);
	return(0);
}
