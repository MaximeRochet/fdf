/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:03:51 by mrochet           #+#    #+#             */
/*   Updated: 2021/07/04 14:59:02 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*read_file(char *fichier, t_data *data)
{
	int		fd;
	char	buffer[100];
	char	*fc;
	int		read_value;
	char	*tmp;

	fc = NULL;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		exit(0);
	read_value = 1;
	while (read_value)
	{
		read_value = read(fd, &buffer, 99);
		buffer[read_value] = '\0';
		tmp = ft_strjoin(fc, buffer);
		free(fc);
		fc = tmp;
	}
	close (fd);
	return (fc);
}

void	size_array(char **tab, t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (tab[0][i])
	{
		if (ft_isdigit(tab[0][i]))
		{
			x++;
			while (ft_isdigit(tab[0][i]) && tab[0][i])
				i++;
		}
		else
			i++;
	}
	i = -1;
	while (tab[++i])
		y++;
	data->width = x;
	data->height = y;
}

int	**malloc_array(char **tab, t_data *data)
{
	int	**array;
	int	y;

	size_array(tab, data);
	y = data->height;
	array = (int **)ft_calloc(sizeof(int *), data->height);
	if (!array)
		return (NULL);
	while (y > 0)
	{
		array[--y] = (int *)ft_calloc(sizeof(int), data->width);
		if (!array[y])
			return (NULL);
	}
	return (array);
}

int	**fill_array(char **tab, t_data *data)
{
	int	i;
	int	y;
	int	x;
	int	**array;

	array = malloc_array(tab, data);
	if (!array)
		return (NULL);
	y = -1;
	while (tab[++y])
	{
		i = 0;
		x = 0;
		while (tab[y][i])
		{
			array[y][x] = ft_atoi(tab[y] + i);
			x++;
			while ((ft_isdigit(tab[y][i]) || tab[y][i] == '-' ) && tab[y][i])
				i++;
			while (tab[y][i] == 32 && tab[y][i])
				i++;
		}
	}
	return (array);
}

int	**create_array(int ac, char **av, t_data *data)
{
	char	**tab;
	char	*map;
	int		**array;
	int		fd;

	fd = open (av[1], O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		exit(0);
	}
	map = read_file(av[1], data);
	tab = ft_split(map, '\n');
	free(map);
	array = fill_array(tab, data);
	fd = -1;
	while (tab[++fd])
		free(tab[fd]);
	free(tab);
	return (array);
}
