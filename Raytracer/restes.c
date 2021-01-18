/*vector = ft_multi_vector(light.colors, b->colors);
vector = ft_multi_reel(vector, angle);

int             ft_motion_notify(int x, int y, t_scene *s)
{
    (void)s;
    printf("x : %d\t y : %d\n", x, y);
    return (0);
}

int             ft_mouse_press(int button, int x, int y, t_scene *s)
{
    (void)s;
    if (button == 1)
        printf("x : %d\t y : %d\n", x, y);
    return (0);
}

mlx_hook(data.mlx_win, 6, 1L<<6, ft_motion_notify, s);
mlx_hook(data.mlx_win, 4, 1L<<2, ft_mouse_press, s);

//BOITE AVEC PLANS --> 6 PLANS
pl 0,-1,0 0,0,0 255,0,0
pl 3,-1,0 0,0,0.5 255,0,0
pl -3,-1,0 0,0,-0.5 255,0,0
pl 0,-1,3 -0.5,0,0 255,0,0
pl 0,2,0 0,0,0 255,0,0
c 0,0,-5 0,0,1 0
R 500 250
A 0.0 128,128,128
l 0,0,-2 1 255,255,255

//CUBES --> 6 CARRES
sq -0.75,0,0 0,0,-0.5 1.5 255,255,0
sq 0,-0.75,0 0,0,0 1.5 0,255,0
sq 0.75,0,0 0,0,0.5 1.5 0,0,255
sq 0,0,0.75 0.5,0,0 1.5 255,0,0
sq 0,0.75,0 0,0,0 1.5 255,0,255
c 0,0,-5 0,0,1 0
R 500 250
A 0.0 128,128,128
l 0,0,-2 1 255,255,255
*/