/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:13:05 by vfedorov          #+#    #+#             */
/*   Updated: 2024/01/19 21:37:07 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_af(const char *ptr, int i)
{
	double	tiv;
	double	ket;

	tiv = 0;
	ket = .1;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		tiv = tiv * 10 + (ptr[i] - '0');
		i++;
	}
	if (ptr[i] == '.')
		i++;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		tiv += (ptr[i] - '0') * ket;
		ket *= 0.1;
		i++;
	}
	if (ptr[i])
		error(1);
	return (tiv);
}

double	ft_atof(const char *ptr)
{
	double	nshan;
	int		i;

	i = 0;
	nshan = 1.;
	while (ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == ' ' || ptr[i] == '\r')
		i++;
	if (ptr[i] == '+')
		i++;
	if (ptr[i] == '-')
	{
		nshan = -1.;
		i++;
	}
	return (nshan * ft_af(ptr, i));
}
