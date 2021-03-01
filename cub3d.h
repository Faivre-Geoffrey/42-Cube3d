/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:53:37 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:50:57 by gefaivre         ###   ########.fr       */
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


int		rgbtohex(int *tab);

void    display_list(t_list *list);
int		ft_lstlongest(t_list *lst);

void make_R(t_struct *s_parsing, char *str);
void make_F(t_struct *s_parsing, char *str);
void make_C(t_struct *s_parsing, char *str);

void    fonction_bidon(void *bidon);
void make_map(t_list **map, t_struct *s_parsing, char *str);
void redirect_args(t_list **map, t_struct *s_parsing, char *string);
char	**make_struct(t_struct *s_parsing);

void	printdeg(t_data *img, t_struct *s_parsing);
