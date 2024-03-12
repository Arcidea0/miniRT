/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:20:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/12 21:35:45 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	count_of_split(char **str, int count)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	if (i != count)
		error(1);
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}

int	parc(char *line, t_entire **ent)
{
	int			i;
	char		**str;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\t' || line[i] == '\n')
			line[i] = ' ';
	str = ft_split(line, ' ');
	id_check(str, ent);
	free_split(str);
	return (0);
}
