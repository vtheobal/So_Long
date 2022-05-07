/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:26:07 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 09:49:36 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_w(t_game *game)
{
	int	k;

	k = 0;
	k = game->pers_y;
	k--;
	if (game->mas1[k][game->pers_x] != '1')
	{
		game->step++;
		if (game->mas1[k][game->pers_x] == 'E' && game->coin == 0)
			ft_error_number(10, game);
		if (game->mas1[k][game->pers_x] == 'E' && game->coin != 0)
		{
			game->flag_E = 1;
			game->exit_x = game->pers_x;
			game->exit_y = k;
		}
		game->mas1[game->pers_y][game->pers_x] = '0';
		game->pers_y--;
		game->mas1[game->pers_y][game->pers_x] = 'P';
	}
}

void	ft_s(t_game *game)
{
	int	k;

	k = 0;
	k = game->pers_y;
	k++;
	if (game->mas1[k][game->pers_x] != '1')
	{
		game->step++;
		if (game->mas1[k][game->pers_x] == 'E' && game->coin == 0)
			ft_error_number(10, game);
		if (game->mas1[k][game->pers_x] == 'E' && game->coin != 0)
		{
			game->flag_E = 1;
			game->exit_x = game->pers_x;
			game->exit_y = k;
		}
		game->mas1[game->pers_y][game->pers_x] = '0';
		game->pers_y++;
		game->mas1[game->pers_y][game->pers_x] = 'P';
	}
}

void	ft_a(t_game *game)
{
	int	k;

	k = 0;
	k = game->pers_x;
	k--;
	if (game->mas1[game->pers_y][k] != '1')
	{
		game->step++;
		if (game->mas1[game->pers_y][k] == 'E' && game->coin == 0)
			ft_error_number(10, game);
		if (game->mas1[game->pers_y][k] == 'E' && game->coin != 0)
		{
			game->flag_E = 1;
			game->exit_x = k;
			game->exit_y = game->pers_y;
		}
		game->mas1[game->pers_y][game->pers_x] = '0';
		game->pers_x--;
		game->mas1[game->pers_y][game->pers_x] = 'P';
	}
}

void	ft_d(t_game *game)
{
	int	k;

	k = 0;
	k = game->pers_x;
	k++;
	if (game->mas1[game->pers_y][k] != '1')
	{
		game->step++;
		if (game->mas1[game->pers_y][k] == 'E' && game->coin == 0)
			ft_error_number(10, game);
		if (game->mas1[game->pers_y][k] == 'E' && game->coin != 0)
		{
			game->flag_E = 1;
			game->exit_x = k;
			game->exit_y = game->pers_y;
		}
		game->mas1[game->pers_y][game->pers_x] = '0';
		game->pers_x++;
		game->mas1[game->pers_y][game->pers_x] = 'P';
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13)
		ft_w(game);
	if (keycode == 1)
		ft_s(game);
	if (keycode == 0)
		ft_a(game);
	if (keycode == 2)
		ft_d(game);
	if (keycode == 53)
		ft_error_number(10, game);
	if (game->flag_E == 0)
		game->mas1[game->exit_y][game->exit_x] = 'E';
	if (game->flag_E > 0)
		game->flag_E--;
	if (game->pers_x == game->exit_x && game->pers_y == game->exit_y)
		game->mas1[game->exit_y][game->exit_x] = 'P';
	otrisovka(game);
	return (0);
}
