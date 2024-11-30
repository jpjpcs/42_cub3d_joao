/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:55:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/30 18:58:57 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_map_walls_floodfill(t_game *game, const int x, const int y)
{
	if (x < 0 || y < 0 || y >= game->map.rows
		|| x >= (int)ft_strlen(game->map.grid[y]) || game->map.grid[y][x] == 32)
	{
		printf("Invalid Map(Not Wall Closed)\n");
		//free_double_pointer_array(map);
		//ft_quit_game(game);
	}
	if (game->map.grid[y][x] == '1')
		return (1);
	game->map.grid[y][x] = '1';
	check_map_walls_floodfill(game, x + 1, y);
	check_map_walls_floodfill(game, x - 1, y);
	check_map_walls_floodfill(game, x, y + 1);
	check_map_walls_floodfill(game, x, y - 1);
	return (0);
}

void set_spawn (t_game *game, const char *line)
{
    int i;
    int j;

    i = 0;
    while (line[i])
    {
        j = 0;
        while (line[j])
        {
            if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
            {
                game->player.x = j;
                game->player.y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

int check_map_characters (const char *line)
{
    while (*line)
    {
        if (!ft_strchr("01NSWE", *line))
        {
            exit_error(NULL, "Error\nInvalid map character.\n");
            return (1);
        }
        line++;
    }
    return (0);
}

void parse_check_map(t_game *game, char *file)
{
    int valid_map;
	int		i;

    i = 0;
   
    check_map_characters (file);
    set_spawn (game, file);
	valid_map = check_map_walls_floodfill (game, game->player.y, game->player.x);
    if (valid_map)
        exit_error(game, "Error\nInvalid map.\n");
}
