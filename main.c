/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:56 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/19 13:54:02 by gefaivre         ###   ########.fr       */
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

void make_map(t_struct *s_parsing, char *str)
{
	static int i;
	s_parsing->map->content = malloc(sizeof(char) * (strlen(str) + 1));
	if (s_parsing->map->content == NULL)
		return ;
	ft_strlcpy(s_parsing->map->content, str, strlen(str))





	i++;
}

void redirect_args(t_struct *s_parsing, char *string)
{
	if (string[0] == 'R' && 1) // 1 = fonction de verification de string
		make_R(s_parsing, string);
	if (string[0] == 'F' && 1)
		make_F(s_parsing, string);
	if (string[0] == 'C' && 1)
		make_C(s_parsing, string);
	if (all_str_is_map(string) && 1)
		make_map(s_parsing, string);
}

void make_struct(t_struct *s_parsing)
{
	char *string;
	s_parsing->fd = open("conf.cub", O_RDONLY);
	while (get_next_line(s_parsing->fd, &string))
	{
		redirect_args(s_parsing, string);
	}
	printf("s_parsing->x_render_size	%i\n",s_parsing->x_render_size);
	printf("s_parsing->y_render_size	%i\n",s_parsing->y_render_size);
	printf("s_parsing->ground_color		%i,%i,%i\n",s_parsing->ground_color[0],s_parsing->ground_color[1],s_parsing->ground_color[2]);
	printf("s_parsing->roof_color		%i,%i,%i\n",s_parsing->ground_color[0],s_parsing->roof_color[1],s_parsing->roof_color[2]);

	close(s_parsing->fd);

}

int main()
{
	t_struct s_parsing;
	make_struct(&s_parsing);
	return (0);
}
