#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**clone;
	int		x;
	int		y;
	int		coins;
	int		exits;
	int		player;
	int		moves;
	int		px;
	int		py;
	void	*wall;
	void	*east;
	void	*west;
	void	*south;
	void	*north;
	void	*exit;
	void	*coin;
	void	*bkg;
	int	img_width;
	int	img_height;

}			t_data;

int		main(int argc, char **argv);
int		handle_keypress(int keysym, t_data *data);
int		ft_check_move(t_data *data, int Y, int X);
int		render(t_data *data);
int		ft_collect_coin(t_data *data, int Y, int X);
int		ft_size_map(t_data *data);
int		ft_exit_error(t_data *data, char *str);
int		ft_exit_cross(t_data *data);
int		ft_exit_win(t_data *data, char *str);

char	**ft_read_map(t_data *data, char *mapfile);

void	ft_setup(t_data *data, char **argv);
void	ft_xpm_to_img(t_data *data);
void	ft_put_image(t_data *data, void *xpm, int nextX, int nextY);
void	ft_put_img(t_data *data, char c, int x, int y);
void	ft_check_size(t_data *data);
void	ft_count_objects(t_data *data, char c, int i, int j);
void	ft_check_map(t_data *data, char *mapfile);
void	ft_check_ber(t_data *data, char *str);
void	ft_check_road(int *k, t_data *data, int x, int y);
void	ft_check_objects(t_data *data);
void	ft_check_wall(t_data *data);
void	ft_destroy_img(t_data *data);


size_t	ft_maplenght(t_data *data, int fd, char *mapfile);

# define SIZE 40
# define MLX_ERROR 1
# define WALL "./images/wall.xpm"
# define EAST "./images/east.xpm"
# define WEST "./images/west.xpm"
# define SOUTH "./images/south.xpm"
# define NORTH "./images/north.xpm"
# define EXIT "./images/exit.xpm"
# define COIN "./images/coin.xpm"
# define BKG "./images/bkg.xpm"

#endif
