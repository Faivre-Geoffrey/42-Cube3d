/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:56 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/22 14:56:15 by gefaivre         ###   ########.fr       */
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
		/* printf("content = \"%10.10s\n", (char*)((*map)->content)); */
}


void make_double_tab(t_list *map, char	**tab_map)
{
	int i;

	i = 0;

	tab_map = malloc(sizeof(char*) * (ft_lstsize(map) + 1));
	if(tab_map == NULL)
		return ;

	 while (ft_lstsize(map) > 0)
	{
		tab_map[i] = ft_strdup((char *)map->content);
		map = map->next;

		i++;
	}
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
	 /* for(int i = 0; i < 1; i++)
	{
		ft_putstr_fd(tab_map[i], 1);
		printf("\n");
	} */
}

void make_struct(t_struct *s_parsing)
{
	char	*string;
	t_list	*map;
	char	**tab_map;

	map = NULL;
	s_parsing->fd = open("conf.cub", O_RDONLY);
	printf("%i\n", s_parsing->fd);
	while (get_next_line(s_parsing->fd, &string))
	{
		redirect_args(&map, s_parsing, string);
	}
	close(s_parsing->fd);

	printf("s_parsing->x_render_size	%i\n",s_parsing->x_render_size);
	printf("s_parsing->y_render_size	%i\n",s_parsing->y_render_size);
	printf("s_parsing->ground_color		%i,%i,%i\n",s_parsing->ground_color[0],s_parsing->ground_color[1],s_parsing->ground_color[2]);
	printf("s_parsing->roof_color		%i,%i,%i\n",s_parsing->ground_color[0],s_parsing->roof_color[1],s_parsing->roof_color[2]);
	display_list(map);
	make_double_tab(map, tab_map);
	int i, y;

	i = 0;
	y = 0;
	while (i < 5)
	{
		ft_putchar_fd(tab_map[i][y], 1);
		printf("\n");
		i++;
	}
	/* print_tab(&tab_map[0]); */
/* 	ft_lstclear(&map, &fonction_bidon); */
}

int main()
{
	t_struct s_parsing;
	make_struct(&s_parsing);
	return (0);
}
