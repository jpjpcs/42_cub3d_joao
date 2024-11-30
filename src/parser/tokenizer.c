/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:56:06 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/30 11:34:50 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
1. It checks if the line is empty (contains only spaces).
2. If it finds any character that is not a space, it returns 0.
3. If it finds only spaces, it returns 1.
*/
int is_line_empty(const char *line)
{
    while (*line)
    {
        if (*line != ' ')
            return (0);
        line++;
    }
    return (1);
}

/*
1. It deletes spaces at the beginning of the str.
2. It deletes spaces at the middle (in between) of the str, 
but keeps only one space between words (how: 
if (isspace(str[i]) && (j == 0 || isspace(str[j - 1]))) 
guarantees that. How: if the current character is a space at the 
beginning of the str or if the previous character is a space,
it will skip the current character).
3. It deletes spaces at the end of the str.
4. It "closes" the str with '\0'.
*/
char *trim_spaces(char *str)
{
    int i; 
    int j;

    i = 0;
    j = 0;
    
    if (!str)
        return NULL;
    while (isspace(str[i]))
        i++;
    while (str[i])
    {
        if (isspace(str[i]) && (j == 0 || isspace(str[j - 1])))
            i++;
        else
            str[j++] = str[i++];
    }
    if (j > 0 && isspace(str[j - 1]))
        j--;

    str[j] = '\0';
    return str;
}

/*
1. If the map hasn't started and the line is empty, return.
2. If the map hasn't started and the line has a valid character,
the map has started.
3. If the map has started, add the line to the map (map.grid).
4. If the map hasn't started, add the line to the tokens_params.
*/
void process_line(t_game *game, char *line, int *params_index, int *map_index)
{
    if (!game->map_started && is_line_empty(line))
        return;

    if (!game->map_started && ft_strchr_any(line, "10NSWE"))
        game->map_started = 1;

    if (game->map_started)
        game->map.grid[(*map_index)++] = ft_strdup(line);
    else
        game->tokens_params[(*params_index)++] = trim_spaces(ft_strdup(line));
        
}

/*
1. Open the file.
2. Read the file line by line.
3. Create the map/Allocate memory 
for the map (heap - because we 
don't know the size of the map) 
and create the tokens_params (stack - because we 
know the size of the tokens, in this case 6).
4. Process each line in the process_line function 
just return if the line is empty.
5. Close the file.
6. If the map hasn't started, exit the program.
*/
void split_file(t_game *game, char *file)
{
    int fd = open(file, O_RDONLY);
    char *line;
    int params_index;
    int map_index;

    params_index = 0;
    map_index = 0;
    if (fd == -1)
        exit_error(game, "Couldn't open requested file.");
    game->map.grid = ft_calloc(game->map.rows + 1, sizeof(char *));
    game->tokens_params[6] = NULL;
    if (!game->map.grid)
        exit_error(NULL, "Couldn't allocate memory.");
    while ((line = get_next_line(fd)))
    {
        process_line(game, line, &params_index, &map_index);
        free(line);
    }
    close(fd);
    if (!game->map_started)
        exit_error(NULL, "Error\nMap is missing or invalid.\n");
}
/*
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
*/
void tokenizer (t_game *game, char *file)
{
    int num_params;
    int count;

    num_params = 0;
    count = 0;
    split_file(game, file);
    remove_inside_spaces(game->tokens_params);

    while (game->tokens_params[num_params++])  
        count++;
    if (count != 6)
        exit_error(game, "Error\nInvalid number of parameters.\n");
}
