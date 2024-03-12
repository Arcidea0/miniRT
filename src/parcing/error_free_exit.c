#include "minirt.h"

void	error_with_free2(t_entire *ent, void *tmp, int flag_error)
{
    while (ent->sphere)
	{
		if (ent->sphere->next)
		{
			tmp = ent->sphere;
			ent->sphere = ent->sphere->next;
			free(tmp);
		}
		else
			free(ent->sphere);
		ent->sphere = ent->sphere->next;
	}
	if (flag_error)
		error(1);
}

void	error_with_free1(t_entire *ent, void *tmp, int flag_error)
{
	while (ent->cyl)
	{
		if (ent->cyl->next)
		{
			tmp = ent->cyl;
			ent->cyl = ent->cyl->next;
			free(tmp);
		}
		else
			free(ent->cyl);
		ent->cyl = ent->cyl->next;
	}
	error_with_free2(ent, NULL, flag_error);
}

void	error_with_free(t_entire *ent, int flag_error)
{
	void	*tmp;

	tmp = NULL;
	if (ent->amlight)
		free(ent->amlight);
	if (ent->camera)
		free(ent->camera);
	if (ent->light)
		free(ent->light);
	while (ent->plane)
	{
		if (ent->plane->next)
		{
			tmp = ent->plane;
			ent->plane = ent->plane->next;
			free(tmp);
		}
		else
			free(ent->plane);
		ent->plane = ent->plane->next;
	}
	error_with_free1(ent, NULL, flag_error);
}

void	error(int er)
{
	if (er == 1)
	{
		printf("Error\n");}
	else if (er == 2)
		printf ("u need two arguments: exec and map\n");
	exit(1);
}
