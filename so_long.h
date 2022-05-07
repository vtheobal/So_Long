/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:01:02 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 10:02:59 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*win;
	char	**mas1;
	char	*argv1;
	int		img_width;
	int		img_height;
	int		coin;
	int		flag_pers;
	int		flag_exit;
	int		buff_coin;
	int		pers_x;
	int		pers_y;
	int		exit_x;
	int		exit_y;
	int		per_i;
	int		per_j;
	int		flag_E;
	int		flag_otrisovka_map;
	int		step;
	int		mas[5];
}				t_game;

int		pars_map1(t_game *game);
int		key_hook(int keycode, t_game *game);
void	otrisovka(t_game *game);
void	ft_nulling(t_game *game);
void	ft_perimeter_check(t_game *game);
void	ft_name_chek(t_game *game);
int		ft_item_count(t_game *game);
void	ft_error_number(int i, t_game *game);
void	ft_print_step(t_game *game);
void	ft_validate_map_1(t_game *game);
void	otrisovka_1(t_game *game, char *relative_path, int i, int j);
int		game_end(t_game *game);
int		len(char *str, char symb);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len, int flag_free);
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, char ch);

#endif