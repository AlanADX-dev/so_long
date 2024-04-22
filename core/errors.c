/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:56:25 by aandrieu          #+#    #+#             */
/*   Updated: 2023/04/12 12:56:26 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(t_data *data)
{
	int	i;

	i = 0;
	if ((data->map[0][i++] != '1') || (data->map[i++][0] != '1') ||
			(data->map[i++][data->img_width - 1] != '1' ||
				data->map[data->img_height - 1][i++] != '1'))
		ft_exit_error(data, "\nERROR :\n\tLa carte doit etre bordee de murs.\n\n");
}

void	ft_check_objects(t_data *data)
{
	if (!(data->coins >= 1))
		ft_exit_error(data, "\nERROR :\n\tLe nombre de collectibles doit\
 etre d'au moins un.\n\n");
	if (data->exits != 1)
		ft_exit_error(data, "\nERROR :\n\tNombre de sortie incorrect.\n\n");
	if (data->player != 1)
		ft_exit_error(data, "\nERROR :\n\tNombre de joueur incorrect.\n\n");
}

void	ft_check_road(int *k, t_data *data, int x, int y)
{
	if (data->clone[y][x] == 'C')
		(*k)--;
	if (data->clone[y][x] == 'E')
	{
		data->exits = 0;
		return ;
	}
	if (data->clone[y][x] != '1' && data->clone[y][x] != 'Z')
	{
		data->clone[y][x] = 'Z';
		ft_check_road(k, data, x - 1, y);
		ft_check_road(k, data, x + 1, y);
		ft_check_road(k, data, x, y - 1);
		ft_check_road(k, data, x, y + 1);
	}
}

void	ft_check_ber(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] != '.' || str[i - 3] != 'b'
		|| str[i - 2] != 'e' || str[i - 1] != 'r')
	{
		data->map = NULL;
		ft_exit_error(data, "\nERROR :\n\tLa carte n'est pas en .ber\n\n");
	}
}

void	ft_check_map(t_data *data, char *mapfile)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (data->clone[i])
	{
		j = 0;
		while (data->clone[i][j])
		{
			if (data->clone[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	ft_check_wall(data);
	ft_check_objects(data);
	ft_check_ber(data, mapfile);
	ft_check_road(&k, data, data->px, data->py);
	if (k != 0 || data->exits != 0)
		ft_exit_error(data, "\nERROR :\n\tPas de chemin valable.\n\n");
}
