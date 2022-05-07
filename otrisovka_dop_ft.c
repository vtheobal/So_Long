/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otrisovka_dop_ft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:15:21 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 09:53:45 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_step(t_game *game)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDo not stop!\n");
	printf("  step: %d\n", game->step);
}

void	ft_validate_map_1(t_game *game)
{
	char	*line;

	get_next_line(game->mas[3], &line);
	while (line[game->mas[2]] != '\0')
		++game->mas[2];
	++game->mas[0];
	free(line);
}

void	otrisovka_1(t_game *game, char *relative_path, int i, int j)
{
	char	*relative_path1;
	char	*relative_path2;
	int		win;

	relative_path1 = "./pers.xpm";
	relative_path2 = "./exit.xpm";
	win = 0;
	if (relative_path == relative_path1)
	{
		game->pers_x = i;
		game->pers_y = j;
	}
	if (relative_path == relative_path2 && game->flag_otrisovka_map == 0)
	{
		game->exit_x = i;
		game->exit_y = j;
	}
	game->img = mlx_xpm_file_to_image(game->mlx, relative_path, &win, &win);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->img, i * 64, j * 64);
}
