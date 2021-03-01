/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:53:37 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/26 14:29:07 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct	s_rgb {
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_rgb;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct	s_struct
{
	int		fd;
	int		x_render_size;
	int		y_render_size;
	int		ground_color[3];
	int		roof_color[3];
	int		m_height;
	int		m_width;
	int		mini_map_diviseur;
}					t_struct;

typedef	struct		s_axe
{
	int		y;
	int		x;
	int		y_c;
	int		x_c;
}					t_axe;
