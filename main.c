#include "INC/cub3d.h"

int		ft_destruct(void *taram)
{
	int i;

	i = 0;
	// free(g_no);
	// free(g_so);
	// free(g_ea);
	// free(g_we);
	// free(data->sprite);
	while (mapp[i])
	{
	 	free(mapp[i]);
	 	i++;
	}
	 free(mapp);
	free(g_sp);
	exit(1);
	return (0);
}



int main(int argc,char **argv)
{
	char	*file;
	if (argc != 2)
	{
		printf("%s",argv[1]);
		exit(1);
	}
	file = argv[1];
	read_line(file);
	init();
	init_sprite();
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, param.g_width, param.g_height, "mlx_abdel");
	img.img = mlx_new_image(g_mlx_ptr, param.g_width, param.g_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	loadtexture();
	mlx_hook(g_win_ptr,  2, 0, key_press, &g_cord);
	mlx_loop_hook(g_mlx_ptr,move_player, &g_cord);   
	mlx_hook(g_win_ptr, 3, 0, key_release, &g_cord);
	mlx_hook(g_win_ptr, 17, 0L, ft_destruct, &g_cord);
		//ß\	mlx_destroy_image(g_mlx_ptr,img.img);
	mlx_loop(g_mlx_ptr);
	return(0);
}
