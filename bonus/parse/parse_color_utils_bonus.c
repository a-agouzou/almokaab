/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:16:03 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/19 10:46:44 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	calc_color(unsigned int *rgb, int r, int g, int b)
{
	*rgb += r;
	*rgb <<= 8;
	*rgb += g;
	*rgb <<= 8;
	*rgb += b;
}