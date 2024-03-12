#include "minirt.h"

void	float_range_checker(float *key, float value, int flag_range)
{
	if ((flag_range == 1 && (value >= 0 && value <= 1))
		|| (flag_range == 2 && (value >= -1 && value <= 1)))
		*key = value;
	else
		error(1);
}

void	free_l(char **split_str_1, char **split_str_3)
{
	free(split_str_1[0]);
	free(split_str_1[1]);
	free(split_str_1[2]);
	free(split_str_1);
	free(split_str_3[0]);
	free(split_str_3[1]);
	free(split_str_3[2]);
	free(split_str_3);
}

t_light	*to_struct_l(char **str)
{
	t_light		*list;
	int			i;
	char		**split_str_1;
	char		**split_str_3;

	list = malloc(sizeof(t_light));
	if (!list)
		return (NULL);
	init_l(list);
	count_of_split(str, 4);
	float_range_checker(&(list->ratio), ft_atof(str[2]), 1);
	split_str_1 = ft_split(str[1], ',');
	split_str_3 = ft_split(str[3], ',');
	count_of_split(split_str_1, 3);
	count_of_split(split_str_3, 3);
	i = -1;
	while (++i < 3)
	{
		list->xyz[i] = ft_atof(split_str_1[i]);
		int_range_checker(&(list->rgb[i]), ft_atoi(split_str_3[i]), 1);
	}
	free_l(split_str_1, split_str_3);
	return (list);
}

void	free_pl(char **split_str_1, char **split_str_2, char **split_str_3)
{
	free(split_str_1[0]);
	free(split_str_1[1]);
	free(split_str_1[2]);
	free(split_str_1);
	free(split_str_2[0]);
	free(split_str_2[1]);
	free(split_str_2[2]);
	free(split_str_2);
	free(split_str_3[0]);
	free(split_str_3[1]);
	free(split_str_3[2]);
	free(split_str_3);
}

t_plane	*to_struct_pl(char **str)
{
	t_plane		*list;
	int			i;
	char		**split_str_1;
	char		**split_str_2;
	char		**split_str_3;

	list = malloc(sizeof(t_plane));
	if (!list)
		return (NULL);
	init_pl(list);
	count_of_split(str, 4);
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	split_str_3 = ft_split(str[3], ',');
	count_of_split(split_str_1, 3);
	count_of_split(split_str_2, 3);
	count_of_split(split_str_3, 3);
	i = -1;
	while (++i < 3)
	{
		list->xyz[i] = ft_atof(split_str_1[i]);
		float_range_checker(&(list->norm_vec[i]), ft_atof(split_str_2[i]), 2);
		int_range_checker(&(list->rgb[i]), ft_atoi(split_str_3[i]), 1);
	}
	free_pl(split_str_1, split_str_2, split_str_3);
	return (list);
}
