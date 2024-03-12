/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:21:15 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 17:06:32 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new -> next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back_cyl(t_cyl **lst, t_cyl *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_back_sphere(t_sphere **lst, t_sphere *new)
{
	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				if (!(*lst)->next)
				{
					(*lst)->next = new;
					break ;
				}
				*lst = (*lst)->next;
			}
		}
		else
			*lst = new;
	}
}
