/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:13:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/19 10:14:33 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free (tabs);
}

int	is_data(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) \
	|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "WE ", 3) || \
	!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (c != '\n' && c != '1' && c != '0' && \
	c != 'N' && c != 'E' && c != 'W' && \
	c != 'S' && c != ' ')
		return (0);
	return (1);
}

int	ft_tabs_len(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

char	**ft_tabs_dup(char **map)
{
	int		size;
	char	**new_map;
	int		index;

	size = ft_tabs_len(map);
	index = 0;
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		return (NULL);
	while (map[index])
	{
		new_map[index] = ft_strdup(map[index]);
		index++;
	}
	new_map[index] = NULL;
	return (new_map);
}
