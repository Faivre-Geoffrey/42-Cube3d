/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdeg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:23:07 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:52:23 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	printdeg(t_data *img, t_struct *s_parsing)
{
	t_axe axe;
	axe.x = 0;
	while (axe.x < s_parsing->x_render_size)
	{
		axe.y = 0;
		while (axe.y < s_parsing->y_render_size)
		{
			printscare(&axe, 1, img, 14443520);
			axe.y++;
		}
		axe.x++;
	}
}
