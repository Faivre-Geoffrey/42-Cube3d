/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:56 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:57:59 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"





void	print_tab(char **tab_map)
{
	int i;

	i = 0;

	while (i < 5)
	{
		ft_putstr_fd(tab_map[i], 1);
		printf("\n");
		i++;
	}
}

void display_map(char **tab_map ,t_struct *s_parsing)
{
	int	x;
	int	y;

	x = 0;
	while (x < s_parsing->m_height)
	{
		y = 0;
		while (y < s_parsing->m_width)
		{
			printf("%c", tab_map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void	printscare(t_axe *axe, int m, t_data  *img, int color)
{
	int x = axe->x;
	int y = axe->y;
	int x_count = 0;
	int y_count = 0;
	int y_save = y;

	while (x_count < m)
	{
		y_count = 0;
		y = y_save;
		while (y_count < m)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
			y_count++;
		}
		x++;
		x_count++;

	}
}

int intmin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int intmax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	printmap(t_data *img, t_struct *s_parsing, char **map)
{
	t_axe axe;
	axe.x = 0;
	axe.x_c = 0;
	s_parsing->m_width -= 4;
	s_parsing->m_height -= 4;
	int diviseur = intmin(s_parsing->x_render_size, s_parsing->y_render_size) / intmax(s_parsing->m_width, s_parsing->m_height);

	printf("diviseur = %i\n", diviseur);
	printf("s_parsing->m_height = %i\n", s_parsing->m_height);
	printf("s_parsing->m_width = %i\n", s_parsing->m_width);
	printf("s_parsing->x_render_size = %i\n", s_parsing->x_render_size);
	printf("s_parsing->y_render_size = %i\n", s_parsing->y_render_size);
	printf("s_parsing->m_width *  diviseur= %i\n", s_parsing->m_width *  diviseur);

	while (axe.x_c < s_parsing->m_width)
	{
		axe.y = 0;
		axe.y_c = 0;
		while (axe.y_c < s_parsing->m_height)
		{
			if (map[axe.y_c + 2][axe.x_c + 2] == '0')
				printscare(&axe, diviseur, img, 0X00FFFFFF);
			else if (map[axe.y_c + 2][axe.x_c + 2] == ' ')
				printscare(&axe, diviseur, img, 0x00650000);
			else
				printscare(&axe, diviseur, img, 0x0066D0E8);
			axe.y = axe.y + diviseur;
			axe.y_c++;
		}
		axe.x = axe.x + diviseur;
		axe.x_c++;
	}
	printf("NO SEG FAULT");
}

int main()
{
	char **map;
	void    *mlx;
    void    *mlx_win;
    t_data  img;
	t_struct s_parsing;


	map = make_struct(&s_parsing);
	display_map(map, &s_parsing);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, s_parsing.x_render_size, s_parsing.y_render_size, "Hello world!");
    img.img = mlx_new_image(mlx, s_parsing.x_render_size, s_parsing.y_render_size);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	printmap(&img, &s_parsing, map);
	/* printdegra(&img, &s_parsing); */

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);




	return (0);
}
