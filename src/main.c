/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:38 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/02/29 20:30:52 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	all_exists(t_entire *ent)
{
	if (!ent->amlight || !ent->camera
		|| !ent->light)
		error_with_free(ent, 1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_cross(t_entire *ent, int keycode)
{
	ft_putstr("Avart\n");
	(void)keycode;
	if (ent->mlx && ent->win)
		mlx_destroy_window(ent->mlx, ent->win);
	if (ent->mlx && ent->img.img)
		mlx_destroy_image(ent->mlx, ent->img.img);
	exit(0);
}

int key_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	// printf("keycode: %d\n", keycode);
	(void)param;
	return (0);
}

int	main(int ac, char **av)
{
	t_entire	entire;
	t_entire	*ent;
	int x = WIDTH, y = HEIGHT;
	
	init_ent(&entire);
	ent = &entire;
	if (ac != 2)
		error(2);
		// (void)av;
	readmap(av[1], &ent);
	all_exists(ent);
	// print_entire(&ent);
	error_with_free(ent, 0);
	
	ent->mlx = mlx_init();
	ent->win = mlx_new_window(ent->mlx, WIDTH, HEIGHT, "miniRT");
	mlx_hook(ent->win, 17, (1L << 17), key_cross, ent);
	mlx_hook(ent->win, 02, 0, key_hook, ent);
	ent->img.img = mlx_new_image(ent->mlx, WIDTH, HEIGHT);
	ent->img.addr = mlx_get_data_addr(ent->img.img, &ent->img.bits_per_pixel, &ent->img.line_length, &ent->img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	while (x >= 0)
	{
		y = HEIGHT;
		while (y >= 0)
		{
			double result = pow(x - WIDTH/2, 2) + pow(y - HEIGHT/2, 2);
			if (result <= pow(100, 2))
				my_mlx_pixel_put(&ent->img, x, y, 0x00FF0000);
			y--;
		}
		x--;
	}
	mlx_put_image_to_window(ent->mlx, ent->win, ent->img.img, 0, 0);
	// init_image(&data);
	// color_back(&data.simg.img);
	mlx_loop(ent->mlx);

	// system("leaks miniRT");
	return (0);
}
