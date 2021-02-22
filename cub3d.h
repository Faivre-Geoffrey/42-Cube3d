/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:53:37 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/22 08:02:28 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


typedef	struct		s_struct
{
	int fd;
	int x_render_size;
	int y_render_size;
	int ground_color[3];
	int roof_color[3];
	t_list *map;
}					t_struct;
