/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:01:43 by mrochet           #+#    #+#             */
/*   Updated: 2021/07/03 17:36:34 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				*ptr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct s_data
{
	int		**array;
	int		zoom;
	int		height;
	int		width;
	int		color;
	int		xwin;
	int		ywin;
	double	x;
	double	y;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	image;
}				t_data;

char	*read_file(char *fichier, t_data *data);
int		**malloc_array(char **tab, t_data *data);
void	size_array(char **tab, t_data *data);
char	*create_file(char *file, t_data *data);
int		**fill_array(char **tab, t_data *data);
int		**create_array(int ac, char **av, t_data *data);
void	bresenham(double x1, double y1, t_data *data);
void	draw(t_data *data);

#endif
