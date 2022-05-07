/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:35:22 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 11:46:29 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_relative_path(char ch, t_game *game)
{
	int	i;

	i = 0;
	if (ch == '1')
		return ("./wall.xpm");
	if (ch == 'P')
		return ("./pers.xpm");
	if (ch == '0')
		return ("./zero.xpm");
	if (ch == 'C')
	{
		game->buff_coin++;
		return ("./coin.xpm");
	}
	if (ch == 'E')
		return ("./exit.xpm");
	return (0);
}

void	otrisovka(t_game *game)
{
	char	*relative_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_print_step (game);
	while (j < game->img_height)
	{
		while (i < game->img_width)
		{
			relative_path = ft_relative_path(game->mas1[j][i], game);
			otrisovka_1(game, relative_path, i, j);
			relative_path = 0;
			i++;
		}
		i = 0;
		j++;
	}
	game->coin = game->buff_coin;
	game->buff_coin = 0;
}

void	ft_validate_map(t_game *game)
{
	char	*line;

	game->mas[0] = 0;
	game->mas[1] = 0;
	game->mas[2] = 0;
	game->mas[3] = open(game->argv1, O_RDONLY);
	ft_validate_map_1 (game);
	while (get_next_line(game->mas[3], &line) == 1)
	{
		while (line[game->mas[1]] != '\0')
			++game->mas[1];
		if (game->mas[2] != game->mas[1])
			ft_error_number(2, game);
		game->mas[1] = 0;
		++game->mas[0];
		free(line);
	}
	free(line);
	if (game->mas[2] > 50 || game->mas[0] + 1 > 50)
		ft_error_number(3, game);
	game->img_width = game->mas[2];
	game->img_height = game->mas[0] + 1;
	close(game->mas[3]);
}

void	ft_ckek_fd(t_game *game)
{
	int		fd;
	int		nn;
	char	*buff;
	char	*line;

	buff = 0;
	fd = 0;
	fd = open(game->argv1, O_RDONLY);
	nn = get_next_line(fd, &line);
	free(line);
	close(fd);
	if (nn < 0)
		ft_error_number(-1, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_number (1, &game);
	game.argv1 = argv[1];
	ft_ckek_fd (&game);
	ft_name_chek (&game);
	ft_nulling(&game);
	ft_validate_map(&game);
	pars_map1(&game);
	ft_item_count (&game);
	ft_perimeter_check (&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.img_width * 64, \
	game.img_height * 64, "So_long");
	game.buff_coin = 0;
	game.coin = 0;
	otrisovka(&game);
	game.flag_otrisovka_map = 1;
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, game_end, &game);
	mlx_loop(game.mlx);
}
