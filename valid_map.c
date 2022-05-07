/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:05:54 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 10:49:49 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_name_chek(t_game *game)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	j = 0;
	str1 = "reb.";
	str2 = game->argv1;
	while (str2[i])
		i++;
	i--;
	while (str1[j] != '\0')
	{
		if (str1[j] != str2[i])
			ft_error_number (4, game);
		j++;
		i--;
	}
}

void	ft_nulling(t_game *game)
{
	game->per_i = 0;
	game->per_j = 0;
	game->flag_pers = 0;
	game->flag_exit = 0;
	game->flag_E = 0;
	game->flag_otrisovka_map = 0;
	game->coin = 0;
	game->step = 0;
}

void	ft_perimeter_check(t_game *game)
{
	while (game->per_j <= game->img_height)
	{
		if (game->per_j == 0 || game->per_j == game->img_height - 1)
		{
			while (game->per_i < game->img_width)
			{
				if (game->mas1[game->per_j][game->per_i] != '1')
					ft_error_number (7, game);
				game->per_i++;
			}
		}
		if (game->per_j > 0 && game->per_j < game->img_height - 1)
		{
			while (game->per_i < game->img_width)
			{
				if (game->mas1[game->per_j][0] != '1' || \
					game->mas1[game->per_j][game->img_width - 1] != '1')
					ft_error_number (7, game);
				game->per_i++;
			}
		}
		game->per_j++;
		game->per_i = 0;
	}
}

int	ft_ckek_count(char ch, t_game *game)
{
	if (ch == 'P')
		game->flag_pers++;
	else if (ch == 'E')
		game->flag_exit++;
	else if (ch == 'C')
		game->coin++;
	else if (ch == '0')
		return (0);
	else if (ch == '1')
		return (0);
	else
		ft_error_number (6, game);
	return (0);
}

int	ft_item_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->img_height)
	{
		while (i < game->img_width)
		{
			ft_ckek_count(game->mas1[j][i], game);
			i++;
		}
		i = 0;
		j++;
	}
	if (game->flag_pers == 1 && game->flag_exit && game->coin)
		return (0);
	else
		ft_error_number (5, game);
	return (0);
}
