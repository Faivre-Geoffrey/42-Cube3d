/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:27:32 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/19 13:27:34 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->content = content;
	return (rtn);
}
