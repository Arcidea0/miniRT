/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:25:18 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/12 21:34:48 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	readmap(char *str, t_entire **ent)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error(1);
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\0')
		error(1);
	while (line)
	{
		if (line[0] == '#')
		{}
		else if (line[0] != '\n')
			parc(line, ent);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
