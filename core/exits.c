/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:50 by aandrieu          #+#    #+#             */
/*   Updated: 2023/04/12 12:44:51 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->east);
	mlx_destroy_image(data->mlx, data->west);
	mlx_destroy_image(data->mlx, data->south);
	mlx_destroy_image(data->mlx, data->north);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->coin);
	mlx_destroy_image(data->mlx, data->bkg);
}

int	ft_exit_win(t_data *data, char *str)
{
	int	i;

	i = 0;
	printf("%s", str);
	ft_destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (data->map[i])
	{
		free(data->clone[i]);
		free(data->map[i]);
		i++;
	}
	free(data->clone);
	free(data->map);
	free(data);
	exit (0);
}

int	ft_exit_cross(t_data *data)
{
	int	i;

	i = 0;
	printf("\n\n\t\tVous avez quitter le jeu. \U0001F622\n\n");
	ft_destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (data->map[i])
	{
		free(data->clone[i]);
		free(data->map[i]);
		i++;
	}
	free(data->clone);
	free(data->map);
	free(data);
	exit (0);
}

int	ft_exit_error(t_data *data, char *str)
{
	int	i;

	i = 0;
	printf("%s", str);
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->clone[i]);
			free(data->map[i]);
			i++;
		}
		free(data->clone);
		free(data->map);
	}
	free(data);
	exit (0);
}
