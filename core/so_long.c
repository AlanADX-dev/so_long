#include "so_long.h"

int	ft_check_move(t_data *data, int Y, int X)
{
	if (data->map[Y][X] == '1')
		return (0);
	else if (data->map[Y][X] == 'C')
	{
		ft_collect_coin(data, Y, X);
		return (1);
	}
	else if (data->map[Y][X] == 'E' && data->coins == 0)
	{
		printf("\n\n\t\t   Nombre de deplacements : %d\n", ++data->moves);
		ft_exit_win(data, "\t\t\U0001F525 Vous avez gagne ! BRAVO !!!\
 \U0001F525\n\n");
		return (1);
	}
	else if (data->map[Y][X] == 'P')
		return (1);
	else if (data->map[Y][X] == 'E' && data->coins != 0)
		return (0);
	return (1);
}

int	handle_keypress(int keysym, t_data *data)
{
	int	x;
	int	y;

	x = data->x / SIZE;
	y = data->y / SIZE;
	if (keysym == XK_Escape)
		ft_exit_win(data, "\n\n\t\tVous avez quitter le jeu. \U0001F622\n\n");
	if (keysym == XK_d && ft_check_move(data, y, x + 1) == 1)
		ft_put_image(data, data->east, data->x + SIZE, data->y);
	if (keysym == XK_a && ft_check_move(data, y, x - 1) == 1)
		ft_put_image(data, data->west, data->x - SIZE, data->y);
	if (keysym == XK_w && ft_check_move(data, y - 1, x) == 1)
		ft_put_image(data, data->north, data->x, data->y - SIZE);
	if (keysym == XK_s && ft_check_move(data, y + 1, x) == 1)
		ft_put_image(data, data->south, data->x, data->y + SIZE);
	return (0);
}

void	ft_xpm_to_img(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->x, &data->y);
	data->east = mlx_xpm_file_to_image(data->mlx, EAST, &data->x, &data->y);
	data->west = mlx_xpm_file_to_image(data->mlx, WEST, &data->x, &data->y);
	data->south = mlx_xpm_file_to_image(data->mlx, SOUTH, &data->x, &data->y);
	data->north = mlx_xpm_file_to_image(data->mlx, NORTH, &data->x, &data->y);
	data->bkg = mlx_xpm_file_to_image(data->mlx, BKG, &data->x, &data->y);
	data->coin = mlx_xpm_file_to_image(data->mlx, COIN, &data->x, &data->y);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->x, &data->y);
}

void	ft_setup(t_data *data, char **argv)
{
	data->map = ft_read_map(data, argv[1]);
	data->clone = ft_read_map(data, argv[1]);
	data->coins = 0;
	data->player = 0;
	data->exits = 0;
	data->moves = 0;
	ft_size_map(data);
	ft_check_map(data, argv[1]);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc != 2)
		ft_exit_error(data, "\nERROR :\n\tNombre d'arguments incorrects.\n\n");
	ft_setup(data, argv);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, data->img_width * SIZE,
			data->img_height * SIZE, "First 2D game :)=");
	if (data->win == NULL)
	{
		free(data->win);
		return (MLX_ERROR);
	}
	ft_xpm_to_img(data);
	render(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win, 17, 1L << 0, ft_exit_cross, data);
	mlx_loop(data->mlx);
}
