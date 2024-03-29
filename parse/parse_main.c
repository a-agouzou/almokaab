/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:53:16 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/20 21:31:13 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_images_paths(t_map_data *map_data)
{
	if (!map_data->north_img_path || !map_data->south_img_path \
	|| !map_data->east_img_path || !map_data->west_img_path)
		return (1);
	return (0);
}

int	parse_map_content(t_map_data *map_data)
{
	if (!map_data->map_body)
		return (1);
	if (check_items(map_data->map_body))
		return (print_error(NITEM), 1);
	fill_map(map_data);
	if (check_if_enclosed_by_walls(map_data))
		return (print_error(NWALLS), 1);
	return (0);
}

int	check_map_extension(char *filename)
{
	int	size;

	size = ft_strlen(filename);
	return (ft_strncmp(filename + (size - 4), ".cub", 5));
}

int	check_data(t_map_data *map_data)
{
	if (!map_data->map_body || !map_data->north_img_path || \
	!map_data->south_img_path || !map_data->west_img_path || \
	!map_data->east_img_path || !map_data->floor_color || \
	!map_data->ceil_color)
		return (1);
	return (0);
}

t_map_data	*parser(char **args_values)
{
	char		*map_filename;
	char		**map;
	t_map_data	*map_data;

	map_filename = args_values[1];
	if (check_map_extension(map_filename))
		return (print_error(NEXTENSION), NULL);
	map = read_map_file(map_filename);
	if (!map)
		return (NULL);
	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (ft_free(map), NULL);
	init_data_map(map_data);
	if (costumaize_map_data(map_data, map))
		return (print_error(DDATA), destroy_map_data(map_data), NULL);
	if (check_data(map_data))
		return (print_error(NDATA), destroy_map_data(map_data), NULL);
	if (parse_map_data(map_data))
		return (destroy_map_data(map_data), NULL);
	if (get_palyer_position(map_data) || check_player(map_data))
		return (destroy_map_data(map_data), print_error(NPLAYER), NULL);
	return (map_data);
}
