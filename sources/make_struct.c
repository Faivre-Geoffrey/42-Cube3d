/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:16:18 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:57:17 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	/* int i;
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
	} */
	return (1);
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

char	**make_struct(t_struct *s_parsing)
{
	char	*string;
	t_list	*map;
	char	**tab_map;

	map = NULL;
	s_parsing->fd = open("conf.cub", O_RDONLY);
	while (get_next_line(s_parsing->fd, &string))
	{
		/* printf("oui\n"); */
		redirect_args(&map, s_parsing, string);
	}
	close(s_parsing->fd);
	make_double_tab(map, &tab_map, s_parsing);
	ft_lstclear(&map, fonction_bidon);
	/* if (mapissecure(tab_map) == 1) */
		return (tab_map);
	return NULL;
}
