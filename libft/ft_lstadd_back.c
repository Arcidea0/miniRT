/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:29:14 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 17:37:33 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}

void	ft_lstadd_back_plane(t_plane **lst, t_plane *new)
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
