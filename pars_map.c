/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:08:23 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 09:46:38 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_game *game)
{
	game->mas1 = malloc(sizeof(char **) * game->img_height);
}

int	pars_map1(t_game *game)
{
	int		i;
	char	*line;
	int		fd;

	ft_init_struct(game);
	i = 0;
	fd = open(game->argv1, O_RDONLY);
	while (i < game->img_height)
	{
		get_next_line(fd, &line);
		game->mas1[i] = line;
		++i;
	}
	close(fd);
	return (0);
}
