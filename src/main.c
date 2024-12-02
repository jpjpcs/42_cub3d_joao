/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:08:01 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/02 03:36:36 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* 
// game loops - raycasting loop and game loop.
void cub3d(t_game *game, char *file)
{   
    raycasting(&game);
    mlx_hook(game->win, 2, 1L << 0, &key_press, &game);
    mlx_hook(game->win, 3, 1L << 1, &key_release, &game);
    mlx_hook(game->win, 17, 1L << 17, exit_esc, &game);
    mlx_loop_hook(game->mlx, &raycasting, &game);
    mlx_loop(game->mlx);
}


//Instead of ft_bzero(game, sizeof(t_game)); 
//I could also use memset or calloc or just game = (t_game){0};
static void	init_game(t_game *game)
{ 
    setup_game(game);
    setup_mlx(game);
    setup_textures(game);
} 
*/

/* 
It checks all in one in the same function:
1. check_args
2. check_file_name
3. check_file_extension
4. check_file_open
5. check_empty_file
*/
void parse_check_file(int argc, char *file)
{
    int fd;
    char *line;

    if (argc != 2 || ft_strlen(file) < 5 || 
        ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
        exit_error(NULL, "Invalid arguments, file name, or extension.\n");

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit_error(NULL, "Failed to open requested file.\n");
    while ((line = get_next_line(fd)))
    {
        for (int i = 0; line[i]; i++)
            if (!ft_isspace(line[i]))
            {
                free(line);
                close(fd);
                return ;
            }
        free(line);
    }
    close(fd);
    exit_error(NULL, "The file is empty or contains only whitespace.\n");
}

void    print_game_atributes(t_game *game)
{
    printf("Ceiling color: %d\n", game->ceiling_color);
    printf("Floor color: %d\n", game->floor_color);
    printf("NO texture: %s\n", game->textures[0].path);
    printf("SO texture: %s\n", game->textures[1].path);
    printf("WE texture: %s\n", game->textures[2].path);
    printf("EA texture: %s\n", game->textures[3].path);
}

/* 
parse_check_file (What it does):
1. check_args, check_file_name, check_file_extension, 
check_file_open, check_empty_file: all in one in the same function.

Tokenizer (What it does - separates in tokens, 
that are smaller parts of the file):
1. It divides the file into smaller tokens: 
    tokens_params (parameters file) and map_grid (map). 
2. It takes off spaces at the beginning, 
    at the end (such as trim) as also 
    at the middle (in between) the tokens_params. 
3. Deliver the tokens_params "cleaned" to 
    the lexer_assign and the map_grid "cleaned" 
    to the map_check_load.

Lexer (What it does - checks/validate the tokens 
and decides what to do with them/assigns them):
1. It checks the textures and colors of the 
    tokens_params to check if they are valid.
2. It assigns the textures and colors to the game struct.

parse_check_map (What it does - checks the map):
1. It checks the map characters to see if they are valid.
2. It sets the spawn point of the player in the map.
3. It checks the walls of the map using the floodfill 
    algorithm to validate if the player is surrounded 
    by walls and therefore the map is valid.
*/ 
void parser(t_game *game, int ac, char *file)
{   
    parse_check_file(ac, file);
    tokenizer(game, file); 
    lexer(game);
    print_game_atributes(game);
    parse_check_map(game);
}

/*
1 - Initializes the game struct to zero(all elements).
2 - Parses the file looking for the map and the parameters.
3 - Inits mlx and the textures.
4 - Starts the game loop: the raycasting loop and the game loop. 
5 - At the end, like in so_long, free is done when 
.. we are exiting the game:
... at so_long that happen when we press ESC or X (close window)
... or when we finish the game (collect all collectibles) 
... and go to the exit door.
At cub3d that happen only when we press ESC or X (close window).
We don´t have exit door (games keeps running), so we can 
.. free everything in exit_esc function.
*/
int	main(int ac, char **av)
{
    t_game game;

    game = (t_game){0};
    game.ceiling_color = -1;
    game.floor_color = -1;
    parser (&game, ac, av[1]);
    //init_game(&game);
    //cub3d (&game, av[1]);
    return (0);
}
