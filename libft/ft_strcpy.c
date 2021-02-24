/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:36:17 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/24 10:53:58 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	if (!dst || !src)
		return ;
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
}
