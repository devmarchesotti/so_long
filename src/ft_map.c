/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:36 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:37 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*trim_line(int fd)
{
	char	*trim;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trim = ft_strtrim(line, "\n");
	free(line);
	return (trim);
}

char	**ft_create_map(char *filename, char **map, int *rows, int *cols)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_free(map);
		return (NULL);
	}
	if (ft_read_map(fd, map, rows, cols) == -1)
	{
		ft_free(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

int	ft_read_map(int fd, char **map, int *rows, int *cols)
{
	char	*line;

	line = trim_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if (*rows >= 1024)
		{
			free(line);
			return (-1);
		}
		map[*rows] = line;
		*cols = ft_strlen(line);
		(*rows)++;
		line = trim_line(fd);
	}
	free(line);
	return (0);
}

char	**ft_parse_map(char *filename, int *rows, int *cols)
{
	char	**map;
	int		r;

	if (!ft_strnstr(filename + (ft_strlen(filename) - 4), ".ber", 4))
		return (ft_printf("Error\n.ber"), NULL);
	map = ft_calloc(sizeof(char *), 1024);
	if (!map)
		return (ft_printf("Error\nalloc error"), NULL);
	map = ft_create_map(filename, map, rows, cols);
	if (!map)
	{
		ft_free(map);
		return (ft_printf("Error\nfile not found"), NULL);
	}
	r = ft_checker(map, *rows, *cols);
	if (r)
	{
		ft_free(map);
		return (NULL);
	}
	return (map);
}
