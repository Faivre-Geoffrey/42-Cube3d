/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_id_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:11:26 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:52:20 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void make_R(t_struct *s_parsing, char *str)
{
	int i;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->x_render_size = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->y_render_size = ft_atoi(str + i);
}

void make_F(t_struct *s_parsing, char *str)
{
	int i;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->ground_color[0] = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->ground_color[1] = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->ground_color[2] = ft_atoi(str + i);

	printf("r = %i\nr = %i\nb = %i\nhex color = %i\n", s_parsing->ground_color[0],s_parsing->ground_color[1],s_parsing->ground_color[2], rgbtohex(s_parsing->ground_color));
}

void make_C(t_struct *s_parsing, char *str)
{
	int i;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->roof_color[0] = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->roof_color[1] = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	if (ft_isdigit(str[i]))
		s_parsing->roof_color[2] = ft_atoi(str + i);
}
