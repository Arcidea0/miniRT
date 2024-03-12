#include "minirt.h"

void	print_entire(t_entire **ent);

void	id_check3(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "sp"))
	{
		if ((*ent)->sphere)
		{
			tmp = (*ent)->sphere;
			ft_lstadd_back_sphere(&((*ent)->sphere), to_struct_sp(str));
		}
		(*ent)->sphere = to_struct_sp(str);
		if (tmp)
			(*ent)->sphere = tmp;
	}
	else if (!ft_strncmp(str[0], "#", 1))
	{
		free_split(str);
		return ;
	}
	else
		error_with_free(*ent, 1);
}

void	print_entire(t_entire **e)
{
	if((*e)->amlight)
	{
		printf("\namlight\nid = %d\n", (*e)->amlight->id);
		printf("ratio = %f\n", (*e)->amlight->ratio);
		printf("rgb = %d,%d,%d\n", (*e)->amlight->rgb[0], (*e)->amlight->rgb[1], (*e)->amlight->rgb[2]);
	}
	
	if((*e)->camera)
	{
		printf("\ncamera\nid = %d\n", (*e)->camera->id);
		printf("xyz = %f,%f,%f\n", (*e)->camera->xyz[0], (*e)->camera->xyz[1], (*e)->camera->xyz[2]);
		printf("norm_vec = %f,%f,%f\n", (*e)->camera->norm_vec[0], (*e)->camera->norm_vec[1], (*e)->camera->norm_vec[2]);
		printf("fov = %d\n", (*e)->camera->fov);
	}

	if((*e)->light)
	{
		printf("\nlight\nid = %d\n", (*e)->light->id);
		printf("xyz = %f,%f,%f\n", (*e)->light->xyz[0], (*e)->light->xyz[1], (*e)->light->xyz[2]);
		printf("ratio = %f\n", (*e)->light->ratio);
		printf("rgb = %d,%d,%d\n", (*e)->light->rgb[0], (*e)->light->rgb[1], (*e)->light->rgb[2]);
	}

	while((*e)->plane)
	{
		printf("\nplane\nid = %d\n", (*e)->plane->id);
		printf("xyz = %f,%f,%f\n", (*e)->plane->xyz[0], (*e)->plane->xyz[1], (*e)->plane->xyz[2]);
		printf("norm_vec = %f,%f,%f\n", (*e)->plane->norm_vec[0], (*e)->plane->norm_vec[1], (*e)->plane->norm_vec[2]);
		printf("rgb = %d,%d,%d\n", (*e)->plane->rgb[0], (*e)->plane->rgb[1], (*e)->plane->rgb[2]);
		(*e)->plane = (*e)->plane->next;
	}

	while((*e)->cyl)
	{
		printf("\ncyl\nid = %d\n", (*e)->cyl->id);
		printf("xyz = %f,%f,%f\n", (*e)->cyl->xyz[0], (*e)->cyl->xyz[1], (*e)->cyl->xyz[2]);
		printf("norm_vec = %f,%f,%f\n", (*e)->cyl->norm_vec[0], (*e)->cyl->norm_vec[1], (*e)->cyl->norm_vec[2]);
		printf("diam = %f\n", (*e)->cyl->diam);
		printf("heig = %f\n", (*e)->cyl->heig);
		printf("rgb = %d,%d,%d\n", (*e)->cyl->rgb[0], (*e)->cyl->rgb[1], (*e)->cyl->rgb[2]);
		(*e)->cyl = (*e)->cyl->next;
	}

	while((*e)->sphere)
	{
		printf("\nsphere\nid = %d\n", (*e)->sphere->id);
		printf("xyz = %f,%f,%f\n", (*e)->sphere->xyz[0], (*e)->sphere->xyz[1], (*e)->sphere->xyz[2]);
		printf("diametr = %f\n", (*e)->sphere->diametr);
		printf("rgb = %d,%d,%d\n", (*e)->sphere->rgb[0], (*e)->sphere->rgb[1], (*e)->sphere->rgb[2]);
		(*e)->sphere = (*e)->sphere->next;
	}

}

void	id_check2(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "cy"))
	{
		if ((*ent)->cyl)
		{
			tmp = (*ent)->cyl;
			ft_lstadd_back_cyl(&((*ent)->cyl), to_struct_cy(str));
		}
		(*ent)->cyl = to_struct_cy(str);
		if (tmp)
			(*ent)->cyl = tmp;
	}
	else
		id_check3(str, ent);
}

void	id_check1(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "L"))
	{
		if ((*ent)->light)
			error_with_free(*ent, 1);
		(*ent)->light = to_struct_l(str);
	}
	else if (!ft_strcmp(str[0], "pl"))
	{
		if ((*ent)->plane)
		{
			tmp = (*ent)->plane;
			ft_lstadd_back_plane(&((*ent)->plane), to_struct_pl(str));
		}
		(*ent)->plane = to_struct_pl(str);
		if (tmp)
			(*ent)->plane = tmp;
	}
	else
		id_check2(str, ent);
}

void	id_check(char **str, t_entire **ent)
{
	void	*tmp;

	tmp = NULL;
	if (!ft_strcmp(str[0], "A"))
	{
		if ((*ent)->amlight)
			error_with_free(*ent, 1);
		(*ent)->amlight = to_struct_a(str);
	}
	else if (!ft_strcmp(str[0], "C"))
	{
		if ((*ent)->camera)
			error_with_free(*ent, 1);
		(*ent)->camera = to_struct_c(str);
	}
	else
		id_check1(str, ent);
}
