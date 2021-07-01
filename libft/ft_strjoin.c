/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:23:38 by mrochet           #+#    #+#             */
/*   Updated: 2021/06/24 13:56:37 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (s1)
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	else
		ret = malloc(sizeof(char ) * ft_strlen(s2) + 1);
	if (!ret)
		return (0);
	if (s1)
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
	while (s2[y])
		ret[i++] = s2[y++];
	ret[i] = '\0';
	return (ret);
}
