/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:50:01 by aandrieu          #+#    #+#             */
/*   Updated: 2023/04/12 12:50:04 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_maplenght(t_data *data, int fd, char *mapfile)
{
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		data->map = NULL;
		ft_exit_error(data, "\nERROR :\n\tLa carte n'existe pas.\n\n");
	}
	while (read(fd, buffer, 1) != 0)
		i++;
	close(fd);
	return (i);
}

char	**ft_read_map(t_data *data, char *mapfile)
{
	int		fd;
	size_t	maplenght;
	char	*buffer;
	char	**map;

	maplenght = ft_maplenght(data, fd, mapfile);
	buffer = malloc(sizeof(char *) * maplenght + 1);
	fd = open(mapfile, O_RDONLY);
	read(fd, buffer, maplenght);
	buffer[maplenght] = '\0';
	close(fd);
	map = ft_split(buffer, '\n');
	free(buffer);
	return (map);
}

void	ft_count_objects(t_data *data, char c, int i, int j)
{
	if (c == 'C')
		data->coins++;
	else if (c == 'P')
	{
		data->player++;
		data->px = j;
		data->py = i;
	}
	else if (c == 'E')
		data->exits++;
	else if (c != '1' && c != 'C' && c != 'P' && c != 'E' && c != '0'
		&& c != '\n' && c != '\0')
		ft_exit_error(data, "\nERROR :\n\tLa carte contient des elements\
 inconnus.\n\n");
}

void	ft_check_size(t_data *data)
{
	if (data->img_width == 0 && data->img_height == 0)
		ft_exit_error(data, "\nERROR :\n\tLa carte est vide.\n\n");
}

int	ft_size_map(t_data *data)
{
	int	i;
	int	j;
	int	w;
	int	h;

	i = 0;
	j = 0;
	w = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			j++;
			ft_count_objects(data, data->map[i][j], i, j);
		}
		w = j;
		j = 0;
		i++;
	}
	h = i;
	data->img_width = w;
	data->img_height = h;
	ft_check_size(data);
	return (1);
}
