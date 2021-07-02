/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:03:51 by mrochet           #+#    #+#             */
/*   Updated: 2021/07/02 16:53:52 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//creer fonction free pour les erreurs
//free tab
//free array

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
		return (0);
	read_value = 1;
	while (read_value)
	{
	//	if(fc)
	//		printf("%d len = %zu \n", read_value, ft_strlen(fc));
		read_value = read(fd, &buffer, 99);
		buffer[read_value] = '\0';
		tmp = ft_strjoin(fc, buffer);
		free(fc);
		fc = tmp;
	}
	close (fd);
	return (fc);
}

void size_array(char **tab, t_data *data)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = -1;
	while(tab[0][++i])
		if(ft_isdigit(tab[0][i]))
		{
			x++;
			while(ft_isdigit(tab[0][i]) && tab[0][i])
				i++;
		}
	i = -1;
	while(tab[++i])
		y++;
	data->width = x;
	data->height = y;
}

int **malloc_array(char **tab, t_data *data)
{
	int **array;
	int y;

	size_array(tab, data);
	
	y = data->height;
	array = ft_calloc(sizeof(int *), data->height);
	if (!array)
		return(NULL);
	while(y >= 0)
	{
		array[y] = ft_calloc(sizeof(int), data->width);
		if(!array[y])
			return(NULL);
		y--;
	}
	return(array);
}

int **fill_array(char **tab, t_data *data)
{
	int	i;
	int	y;
	int x;
	int **array;

	array = malloc_array(tab ,data);
	if(!array)
		return(NULL);
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

int **create_array(int ac, char **av, t_data *data)
{
	char **tab;
	char *map;
	int i;
	int y;
	int **array;

	//verif fichier existant -> deja fait dans read_file
	//verif dossier
	map = read_file(av[1], data);
	tab = ft_split(map, '\n');
	free(map);
	i = -1;
	array = fill_array(tab, data);
	free(tab);
	y = -1;
	printf("hei = %d wid = %d\n", data->height, data->width);	
	while(++y < data->height)
	{
		printf("array[%d] ", y);
		i = -1;
		while(++i < data->width )
		{
			printf("%d " , array[y][i]);
		}
		printf("\n");
	}
	return(array);
}
