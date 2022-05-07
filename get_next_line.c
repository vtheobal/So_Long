/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:11:51 by vtheobal          #+#    #+#             */
/*   Updated: 2021/09/16 09:57:14 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sbros(int reat, char *buff, char *ost)
{
	if (ost)
		free (ost);
	if (buff)
		free(buff);
	if (reat > 0)
		return (1);
	if (reat < 0)
		return (-1);
	return (reat);
}

int	get_next_line(int fd, char **line)
{
	int			reat;
	static char	*os;
	char		*buff;

	reat = 1;
	buff = (char *)malloc(sizeof(char) * 1 + 1);
	if (read(fd, buff, 0) || !line || !buff || 1 <= 0)
		return (sbros(-1, buff, 0));
	while (reat)
	{
		if (ft_strchr(os, '\n') != 0)
			break ;
		reat = read(fd, buff, 1);
		buff[reat] = '\0';
		os = ft_strjoin(os, buff);
		if (!os)
			return (sbros(-1, buff, 0));
	}
	*line = ft_substr(os, 0, len(os, '\n'), 0);
	if (!(*line))
		return (sbros(reat, buff, os));
	os = ft_substr(os, len(os, '\n') + 1, len(os, '\0') - len(os, '\n'), 1);
	if (!os && reat)
		return (sbros(-1, buff, 0));
	return (sbros(reat, buff, 0));
}
