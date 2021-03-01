/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:14:38 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:52:16 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		rgbtohex(int *tab)
{
	t_rgb	rgb;
	int		hex;

	rgb.r = tab[0];
	rgb.b = tab[2];
	rgb.g = tab[1];
	rgb.a = 0;
	hex = *(int *)&rgb;
	return (hex);
}
