#include "minirt.h"

void	int_range_checker(int *key, int value, int flag_range)
{
	if ((flag_range == 1 && (value >= 0 && value <= 255))
		|| (flag_range == 2 && (value >= 0 && value <= 180)))
		*key = value;
	else
		error(1);
}

void	free_a(char **split_str_2)
{
	free(split_str_2[0]);
	free(split_str_2[1]);
	free(split_str_2[2]);
	free(split_str_2);
}

t_amlight	*to_struct_a(char **str)
{
	t_amlight	*list;
	int			i;
	char		**split_str_2;

	list = malloc(sizeof(t_amlight));
	if (!list)
		return (NULL);
	init_a(list);
	count_of_split(str, 3);
	float_range_checker(&(list->ratio), ft_atof(str[1]), 1);
	split_str_2 = ft_split(str[2], ',');
	count_of_split(split_str_2, 3);
	i = -1;
	while (++i < 3)
		int_range_checker(&(list->rgb[i]), ft_atoi(split_str_2[i]), 1);
	free_a(split_str_2);
	return (list);
}

void	free_c(char **split_str_1, char **split_str_2)
{
	free(split_str_1[0]);
	free(split_str_1[1]);
	free(split_str_1[2]);
	free(split_str_1);
	free(split_str_2[0]);
	free(split_str_2[1]);
	free(split_str_2[2]);
	free(split_str_2);
}

t_camera	*to_struct_c(char **str)
{
	t_camera	*list;
	int			i;
	char		**split_str_1;
	char		**split_str_2;

	list = malloc(sizeof(t_camera));
	if (!list)
		return (NULL);
	init_c(list);
	count_of_split(str, 4);
	int_range_checker(&(list->fov), ft_atoi(str[3]), 2);
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	count_of_split(split_str_1, 3);
	count_of_split(split_str_2, 3);
	i = -1;
	while (++i < 3)
	{
		list->xyz[i] = ft_atof(split_str_1[i]);
		float_range_checker(&(list->norm_vec[i]), ft_atof(split_str_2[i]), 2);
	}
	free_c(split_str_1, split_str_2);
	return (list);
}
