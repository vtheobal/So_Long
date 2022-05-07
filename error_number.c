/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:42:22 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 11:58:25 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_end(t_game *game)
{
	ft_error_number(10, game);
	return (0);
}

void	ft_error_number(int i, t_game *game)
{
	if (i == -1)
		printf("ERROR: File reading error");
	if (i == 1)
		printf("ERROR: Wrong number of arguments.");
	if (i == 2)
		printf("ERROR: Invalid width parametr.");
	if (i == 3)
		printf("ERROR: Invalid width and height map");
	if (i == 4)
		printf("ERROR: File permission error.(no .ber)");
	if (i == 5)
		printf("ERROR: Сardinality error");
	if (i == 6)
		printf("ERROR: There are other elements on the map");
	if (i == 7)
		printf("ERROR: Error perimeter (missing wall)");
	if (i == 10)
	{
		printf("Top code!!!");
		free(game->mas1);
	}
	(void) game;
	exit(0);
}
