#include "minirt.h"

void	free_cy(char **split_str_1, char **split_str_2, char **split_str_5)
{
	free(split_str_1[0]);
	free(split_str_1[1]);
	free(split_str_1[2]);
	free(split_str_1);
	free(split_str_2[0]);
	free(split_str_2[1]);
	free(split_str_2[2]);
	free(split_str_2);
	free(split_str_5[0]);
	free(split_str_5[1]);
	free(split_str_5[2]);
	free(split_str_5);
}

t_cyl	*to_struct_cy(char **str)
{
	t_cyl	*list;
	int		i;
	char	**split_str_1;
	char	**split_str_2;
	char	**split_str_5;

	list = malloc(sizeof(t_cyl));
	if (!list)
		return (NULL);
	init_cy(list);
	count_of_split(str, 6);
	list->diam = ft_atof(str[3]);
	list->heig = ft_atof(str[4]);
	split_str_1 = ft_split(str[1], ',');
	split_str_2 = ft_split(str[2], ',');
	split_str_5 = ft_split(str[5], ',');
	count_of_split(split_str_1, 3);
	count_of_split(split_str_2, 3);
	count_of_split(split_str_5, 3);
	i = -1;
	while (++i < 3)
	{
		list->xyz[i] = ft_atof(split_str_1[i]);
		float_range_checker(&(list->norm_vec[i]), ft_atof(split_str_2[i]), 2);
		int_range_checker(&(list->rgb[i]), ft_atoi(split_str_5[i]), 1);
	}
	free_cy(split_str_1, split_str_2, split_str_5);
	return (list);
}

void	free_sp(char **split_str_1, char **split_str_3)
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

t_sphere	*to_struct_sp(char **str)
{
	t_sphere	*list;
	int			i;
	char		**split_str_1;
	char		**split_str_3;

	list = malloc(sizeof(t_sphere));
	if (!list)
		return (NULL);
	init_sp(list);
	count_of_split(str, 4);
	list->diametr = ft_atof(str[2]);
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
	free_sp(split_str_1, split_str_3);
	return (list);
}
