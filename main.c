/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:56 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/25 14:58:03 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int all_str_is_map(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\t'))
			return (0);
		i++;
	}
	if (i < 3)
		return 0;
	return (1);
}

void    display_list(t_list *list)
{
    int     i;
    i = 0;
    while (list->next)
    {
        printf("%s\n", (char*)(list->content));
        i++;
        list = list->next;
    }
	 printf("%s\n", (char*)(list->content));

}

void    fonction_bidon(void *bidon)
{
    (void)bidon;
    return ;
}

void make_map(t_list **map, t_struct *s_parsing, char *str)
{
	t_list *node;

    node = ft_lstnew(str);

    ft_lstadd_back(map, node);

}

void redirect_args(t_list **map, t_struct *s_parsing, char *string)
{
	if (string[0] == 'R' && 1) // 1 = fonction de verification de string
		make_R(s_parsing, string);
	else if (string[0] == 'F' && 1)
		make_F(s_parsing, string);
	else if (string[0] == 'C' && 1)
		make_C(s_parsing, string);
	else if (all_str_is_map(string) && 1)
		make_map(map, s_parsing, string);
}

int		ft_lstlongest(t_list *lst)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (lst)
	{
		if (ft_strlen(lst->content) > size)
			size = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (size);
}

void	set2dtab(char **tab, int x, int y, char c)
{
	int i;
	int j;

	i = 0;

	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			tab[i][j] = c;
			j++;
		}
		i++;
	}
}

void	setframe2dtab(char **tab, int x, int y, char c)
{
	int i;
	int j;

	i = 0;

	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1|| j == 0 || j == x - 1)
				tab[i][j] = c;
			j++;
		}
		i++;
	}
}

void putdataintab(char **tab, int x , int y, t_list *map)
{
	int i;
	int j;

	i = 0;
	x -= 4;
	y -= 4;

	while (i < y)
	{
	j = 0;
		while(((char*)map->content)[j])
		{
			tab[i + 2][j + 2] = ((char*)map->content)[j];
			j++;
		}
		/* printf("print = %c\n",((char*)map->content)[j]); */
		map = map->next;
		i++;
	}
}

int mapissecure(char **tab_map)
{
	int i;
	int j;

	i = 0;
	while (tab_map[i])
	{
		j = 0;
		while(tab_map[i][j])
		{
			if(tab_map[i][j] == '0')
			{
				if (tab_map[i + 1][j] == ' ' || tab_map[i - 1][j] == ' '
				|| tab_map[i][j + 1] == ' ' || tab_map[i][j - 1] == ' ')
				{
					printf("gwos gwos pwoblèm la, El ewe invalid lá map  \n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}


void make_double_tab(t_list *map, char ***tab_map, t_struct *s_parsing)
{
	int i;

	i = 0;
	s_parsing->m_height = ft_lstsize(map) + 4;
	s_parsing->m_width = ft_lstlongest(map) + 4;
	*tab_map = malloc(sizeof(char*) * (s_parsing->m_height));
	if (*tab_map == NULL)
		return ;
	while (i < s_parsing->m_height)
	{
		(*tab_map)[i] = malloc(sizeof(char) * (s_parsing->m_width));
		(*tab_map)[i][s_parsing->m_width] = '\0';
		i++;
	}
	(*tab_map)[i] = NULL;
	set2dtab(*tab_map, s_parsing->m_width, s_parsing->m_height, ' ');
	setframe2dtab(*tab_map, s_parsing->m_width, s_parsing->m_height, '*');
	putdataintab(*tab_map, s_parsing->m_width, s_parsing->m_height, map);
}

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

void display_map(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		printf("%s\n", tab_map[i]);
		i++;
	}
}

char	**make_struct(t_struct *s_parsing)
{
	char	*string;
	t_list	*map;
	char	**tab_map;

	map = NULL;
	s_parsing->fd = open("conf.cub", O_RDONLY);
	while (get_next_line(s_parsing->fd, &string))
	{
		redirect_args(&map, s_parsing, string);
	}
	close(s_parsing->fd);
	make_double_tab(map, &tab_map, s_parsing);
	ft_lstclear(&map, fonction_bidon);
	if (mapissecure(tab_map) == 1)
		return (tab_map);
	return NULL;
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
				printscare(&axe, diviseur - 1, img, 0X00E86a66);
			else
				printscare(&axe, diviseur - 1, img, 0x0066D0E8);
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
	display_map(map);

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, s_parsing.x_render_size, s_parsing.y_render_size, "Hello world!");
    img.img = mlx_new_image(mlx, s_parsing.x_render_size, s_parsing.y_render_size);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	printmap(&img, &s_parsing, map);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);




	return (0);
}
