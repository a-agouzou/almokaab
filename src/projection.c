/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:14:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/08 11:07:49 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// uint32_t get_color(t_data *data, int xoff, int yoff)
// {
//     uint32_t *txtr = (uint32_t *)data->texture->pixels;
//     uint32_t index = (data->texture->width * yoff) + xoff;
//     return(txtr[index]);
// }

uint32_t    reverse_bytes(uint32_t num)
{
	return (((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) \
	| ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000));
}

void    draw_strip(t_map_data *data, int id, int start, int end, float wall_height)
{
	uint32_t color;
	int xoffset;
	int yoffset;
	double x_step;
	double s;
	
	x_step =  data->texture->width / CUB_SIZE;
	if(data->rays.is_verthit)
		xoffset = ((int)((double)data->rays.y_hit * x_step) % data->texture->width);
	else
		xoffset = ((int)((double)data->rays.x_hit * x_step) % data->texture->width);
	uint32_t *txtr = (uint32_t *)data->texture->pixels;
	float texture_scale = (float)data->texture->height / wall_height;
	s = ((start - data->win_height / 2 + wall_height / 2) * texture_scale);
	(void)wall_height;
	while(start < end)
	{
		yoffset = (int)s;
		color = txtr[yoffset * data->texture->width + xoffset];
		s+=texture_scale;
		color = reverse_bytes(color);
		mlx_put_pixel(data->img, id, start , color);
		start++;
	}
}

void    wall_projection(t_map_data *data, int id)
{
	float distance_pp;
	float wall_height;
	float real_dis;
	int start;
	int end;
	// int i;

	// i = 0;
	// while(i < data->num_rays)
	// {
		
		real_dis = data->rays.Distance * cos(data->rays.rayAngle - data->roatAngle);
		distance_pp = (data->win_width / 2) / (tan(data->fov / 2));
		wall_height = distance_pp * (CUB_SIZE / real_dis);
		start = (data->win_height / 2) - ((int)wall_height / 2);
		if(start < 0)
			start = 0;
		end = (data->win_height / 2) + ((int)wall_height / 2);
		if(end > data->win_height)
			end = data->win_height;
		draw_strip(data, id, start,end, wall_height);
		// i++;
	// }
}