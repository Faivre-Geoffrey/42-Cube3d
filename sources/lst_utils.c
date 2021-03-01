/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:19:57 by gefaivre          #+#    #+#             */
/*   Updated: 2021/03/01 08:52:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
