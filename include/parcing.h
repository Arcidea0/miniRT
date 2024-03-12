#ifndef PARCING_H
# define PARCING_H
# define WIDTH 800
# define HEIGHT 600

typedef struct s_ambient_lightning
{
	int		id;
	float	ratio;
	int		rgb[3];
}	t_amlight;

typedef struct s_camera
{
	int		id;
	float	xyz[3];
	float	norm_vec[3];
	int		fov;
}	t_camera;

typedef struct s_light
{
	int		id;
	float	xyz[3];
	float	ratio;
	int		rgb[3];
}	t_light;

typedef struct s_plane
{
	int				id;
	float			xyz[3];
	float			norm_vec[3];
	int				rgb[3];
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	int					id;
	float				xyz[3];
	float				norm_vec[3];
	float				diam;
	float				heig;
	int					rgb[3];
	struct s_cylinder	*next;
}	t_cyl;

typedef struct s_sphere
{
	int				id;
	float			xyz[3];
	float			diametr;
	int				rgb[3];
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_entire
{
	char		*addr;
	void		*mlx;
	void		*win;
	t_img		img;
	t_amlight	*amlight;
	t_camera	*camera;
	t_light		*light;
	t_plane		*plane;
	t_cyl		*cyl;
	t_sphere	*sphere;
}	t_entire;

void		error(int er);
int			parc(char *line, t_entire **ent);
int			a_ligth(char *str);
int			readmap(char *str, t_entire **ent);
void		id_check(char **str, t_entire **ent);
void		count_of_split(char **str, int count);
void		free_a(char **split_str_2);
// void		free_c(char **split_str_1, char **split_str_2);
void		free_l(char **split_str_1, char **split_str_3);
void		free_pl(char **split_str_1, char **split_str_2, char **split_str_3);
void		free_cy(char **split_str_1, char **split_str_2, char **split_str_5);
void		free_sp(char **split_str_1, char **split_str_3);
t_amlight	*to_struct_a(char **str);
t_camera	*to_struct_c(char **str);
t_light		*to_struct_l(char **str);
t_plane		*to_struct_pl(char **str);
t_cyl		*to_struct_cy(char **str);
t_sphere	*to_struct_sp(char **str);
void		int_range_checker(int *key, int value, int flag_range);
void		float_range_checker(float *key, float value, int flag_range);
void		id_check1(char **str, t_entire **ent);
void		error_with_free(t_entire *ent, int flag_error);
void		free_split(char **str);
void		ft_putstr(char *str);


void	print_entire(t_entire **e);

#endif