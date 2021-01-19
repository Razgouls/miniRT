#include "../minirt.h"

void	ft_affiche_ambient_light(t_ambient_light ambient_light)
{
	printf("%c\t", ambient_light.id);
	printf("%f\t", ambient_light.ratio);
	printf("%f,", ambient_light.colors.x);
	printf("%f,", ambient_light.colors.y);
	printf("%f\n", ambient_light.colors.z);
}

void	ft_affiche_res(t_resolution resolution)
{
	printf("%c\t", resolution.id);
	printf("%d,", resolution.res[0]);
	printf("%d\n", resolution.res[1]);
}

void	ft_affiche_camera(t_camera camera)
{
	printf("%c\t", camera.id);
	printf("%f,%f,%f\t", camera.origin.x, camera.origin.y, camera.origin.z);
	printf("%f,%f,%f\t", camera.vect_orient.x, camera.vect_orient.y, camera.vect_orient.z);
	printf("%f\n", camera.fov);
}

void	ft_affiche_plane(t_plane *plane)
{
	printf("%s\t", plane->base.id);
	printf("%f,%f,%f\t", plane->base.origin.x, plane->base.origin.y, plane->base.origin.z);
	printf("%f,%f,%f\t", plane->base.vect_orient.x, plane->base.vect_orient.y, plane->base.vect_orient.z);
	printf("%f,%f,%f\n", plane->base.colors.x, plane->base.colors.y, plane->base.colors.z);
}

void	ft_affiche_sphere(t_sphere *sphere)
{
	printf("%s\t", sphere->base.id);
	printf("%f,%f,%f\t", sphere->base.origin.x, sphere->base.origin.y, sphere->base.origin.z);
	printf("%f\t", sphere->radius);
	printf("%f,%f,%f\n", sphere->base.colors.x, sphere->base.colors.y, sphere->base.colors.z);
}

void	ft_affiche_square(t_square *square)
{
	printf("%s\t", square->base.id);
	printf("%f,%f,%f\t", square->base.origin.x, square->base.origin.y, square->base.origin.z);
	printf("%f,%f,%f\t", square->base.vect_orient.x, square->base.vect_orient.y, square->base.vect_orient.z);
	printf("%f\t", square->height);
	printf("%f,%f,%f\n", square->base.colors.x, square->base.colors.y, square->base.colors.z);
}

void	ft_affiche_cylindre(t_cylindre *cylindre)
{
	printf("%s\t", cylindre->base.id);
	printf("%f,%f,%f\t", cylindre->base.origin.x, cylindre->base.origin.y, cylindre->base.origin.z);
	printf("%f,%f,%f\t", cylindre->base.vect_orient.x, cylindre->base.vect_orient.y, cylindre->base.vect_orient.z);
	printf("%f\t", cylindre->radius);
	printf("%f\t", cylindre->height);
	printf("%f,%f,%f\n", cylindre->base.colors.x, cylindre->base.colors.y, cylindre->base.colors.z);
}

void	ft_affiche_cone(t_cone *cone)
{
	printf("%s\t", cone->base.id);
	printf("%f,%f,%f\t", cone->base.origin.x, cone->base.origin.y, cone->base.origin.z);
	printf("%f,%f,%f\t", cone->base.vect_orient.x, cone->base.vect_orient.y, cone->base.vect_orient.z);
	printf("%f\t", cone->radius);
	printf("%f\t", cone->height);
	printf("%f,%f,%f\n", cone->base.colors.x, cone->base.colors.y, cone->base.colors.z);
}

void	ft_affiche_light(t_light light)
{
	printf("%c\t", light.id);
	printf("%f,%f,%f\t", light.origin.x, light.origin.y, light.origin.z);
	printf("%f\t", light.ratio);
	printf("%f,%f,%f\n", light.colors.x, light.colors.y, light.colors.z);
}

void	ft_affiche_triangle(t_triangle *triangle)
{
	printf("%s\t", triangle->base.id);
	printf("%f,%f,%f\t", triangle->base.origin.x, triangle->base.origin.y, triangle->base.origin.z);
	printf("%f,%f,%f\t", triangle->p1.x, triangle->p1.y, triangle->p1.z);
	printf("%f,%f,%f\t", triangle->p2.x, triangle->p2.y, triangle->p2.z);
	printf("%f,%f,%f\t", triangle->p3.x, triangle->p3.y, triangle->p3.z);
	printf("%f,%f,%f\n", triangle->base.colors.x, triangle->base.colors.y, triangle->base.colors.z);
}

void	ft_affichage_matrice(t_matrice m)
{
	printf("%f\t %f\t %f\t %f\n", m.v_x.x, m.v_x.y, m.v_x.z, m.v_x.t);
	printf("%f\t %f\t %f\t %f\n", m.v_y.x, m.v_y.y, m.v_y.z, m.v_y.t);
	printf("%f\t %f\t %f\t %f\n", m.v_z.x, m.v_z.y, m.v_z.z, m.v_z.t);
	printf("%f\t %f\t %f\t %f\n", m.v_p.x, m.v_p.y, m.v_p.z, m.v_p.t);
}