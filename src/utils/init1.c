#include "minirt.h"

void	init_sp(t_sphere *list)
{
	list->id = 6;
	list->xyz[0] = 0;
	list->xyz[1] = 0;
	list->xyz[2] = 0;
	list->diametr = 0;
	list->rgb[0] = 0;
	list->rgb[1] = 0;
	list->rgb[2] = 0;
	list->next = NULL;
}

void	init_ent(t_entire *ent)
{
	ent->amlight = NULL;
	ent->camera = NULL;
	ent->light = NULL;
	ent->plane = NULL;
	ent->cyl = NULL;
	ent->sphere = NULL;
}
