/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:43:16 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/19 10:46:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	check_value(int value)
{
	return (value < 0 || value > 255);
}

int	ft_check(char *color)
{
	int	index;

	index = 0;
	while (color[index])
	{
		if (!ft_isdigit(color[index]) && !ft_is_space(color[index]))
			return (1);
		index++;
	}
	return (0);
}

int	parse_color(char **color, int *red, int *green, int *blue)
{
	if (!color[0] || !color[1] || !color[2] || color[3])
		return (1);
	if (ft_check(color[0]) || ft_check(color[1]) || ft_check(color[2]))
		return (1);
	*red = ft_atoi(color[0]);
	*green = ft_atoi(color[1]);
	*blue = ft_atoi(color[2]);
	if (check_value(*red) || check_value(*green) || check_value(*blue))
		return (1);
	return (0);
}

int	check_color_str(char *str)
{
	int	index;

	index = 0;
	if (str[index] == ',' || !str[index])
		return (1);
	index++;
	while (str[index])
	{
		if (str[index] == ',' && (str[index + 1] == ',' || !str[index + 1]))
			return (1);
		index++;
	}
	return (0);
}

int	parse_colors_values(t_map_data *map_data)
{
	int		red;
	int		blue;
	int		green;
	char	**color;

	if (!map_data->ceil_color || !map_data->floor_color)
		return (1);
	if (check_color_str(map_data->floor_color) || \
	check_color_str(map_data->ceil_color))
		return (1);
	color = ft_split(map_data->floor_color, ',');
	if (!color)
		return (1);
	if (parse_color(color, &red, &green, &blue))
		return (ft_free(color), 1);
	calc_color(&map_data->floor_rgb, red, green, blue);
	ft_free(color);
	color = ft_split(map_data->ceil_color, ',');
	if (!color)
		return (1);
	if (parse_color(color, &red, &green, &blue))
		return (ft_free(color), 1);
	calc_color(&map_data->ceil_rgb, red, green, blue);
	ft_free(color);
	return (0);
}
