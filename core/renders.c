/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:26 by aandrieu          #+#    #+#             */
/*   Updated: 2023/04/12 12:58:28 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_collect_coin(t_data *data, int Y, int X)
{
	data->map[Y][X] = '0';
	data->coins--;
	printf("\tCOINS A RAMASSER: %d\n", data->coins);
	return (0);
}

void	ft_put_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			x * SIZE, y * SIZE);
	if (c == 'P')
	{
		data->x = x * SIZE;
		data->y = y * SIZE;
		mlx_put_image_to_window(data->mlx, data->win, data->south,
			x * SIZE, y * SIZE);
	}
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coin,
			x * SIZE, y * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			x * SIZE, y * SIZE);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->bkg,
			x * SIZE, y * SIZE);
}

int	render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->win != NULL)
	{
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				ft_put_img(data, data->map[i][j], j, i);
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	ft_put_image(t_data *data, void *xpm, int nextX, int nextY)
{
	mlx_put_image_to_window(data->mlx, data->win, xpm, nextX, nextY);
	mlx_put_image_to_window(data->mlx, data->win, data->bkg, data->x, data->y);
	data->x = nextX;
	data->y = nextY;
	printf("Nombre de coups: %d\n", ++data->moves);
}
