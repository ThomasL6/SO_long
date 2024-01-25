/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:23:21 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/07 13:23:23 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*read_lines_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = get_next_line(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	free(buff);
	return (NULL);
}

char	**parse_map2(t_data *data, int i)
{
	if (check_walls(data))
	{
		ft_printf("Error\nThe map must be closed.\n");
		return (ft_free_map(data));
	}
	if (data->map != NULL)
		data->map_copy = map_copy(data->map);
	if (flood_fill(data) == ERROR)
	{
		ft_printf("Error\nPath invalid\n");
		free_map_no_launch(data->map_copy);
		return (ft_free_map(data));
	}
	data->height = i;
	return (data->map);
}

char	**parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_split(read_lines_map(fd), '\n');
	if (empty_map(data) == 1)
	{
		ft_free_map(data);
		return (0);
	}
	if (check_form(data) == ERROR)
	{
		ft_free_map(data);
		return (0);
	}
	if (check_symbols(data) == ERROR)
	{
		ft_free_map(data);
		return (0);
	}
	count_symb(data);
	return (parse_map2(data, i));
}

char	**map_core(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr_int(str[1], ".ber") == 0)
	{
		ft_printf("Error\nMap must be in .ber\n");
		exit(0);
	}
	fd = open(str[1], O_RDONLY);
	if (fd > 0)
		data->map = parse_map(fd, data);
	else
		ft_printf("Error\nFailled to open file\n");
	if (!data->map)
		return (0);
	if (data->content.count_c < 1)
		ft_printf("Error\nNo collectibles\n");
	if (data->content.count_e != 1 || data->content.count_p != 1)
		ft_printf("Error\nToo many exits or starts\n");
	if (data->content.count_c < 1 || data->content.count_e != 1
		|| data->content.count_p != 1)
		ft_free_map(data);
	return (data->map);
}
