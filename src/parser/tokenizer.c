/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:56:06 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/01 17:23:13 by joaosilva        ###   ########.fr       */
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
void process_line(t_game *game, char *line, int *tokens_index)
{  
    char *trimmed_line = NULL;
    char *old_map_grid = NULL;
    char *tmp_map_grid = ft_strdup("");
    
    trimmed_line = ft_strtrim(line, " ");
    if (!trimmed_line)
        exit_error(game, "Error\nMemory allocation failed in ft_strtrim.");
    if (!game->map_started && is_line_empty(trimmed_line))
    {   
        free(trimmed_line);
        return;
    }
    if (!game->map_started && ft_strchr("NSEWCF", trimmed_line[0])) 
        game->tokens_params[(*tokens_index)++] = ft_strdup(trim_spaces(trimmed_line));
    if (!game->map_started && ft_strchr("10", trimmed_line[0]))
        game->map_started = 1;
    if (game->map_started)
    {
        old_map_grid = tmp_map_grid;
        tmp_map_grid = ft_strjoin(tmp_map_grid, line);
        if(old_map_grid)
            free(old_map_grid);
        if (!tmp_map_grid)
            exit_error(game, "Error\nMemory allocation failed in ft_strjoin.");
        game->tmp_map_grid = tmp_map_grid;
        game->map.rows++;
    }
    //printf("%d ", game->map.rows + 1); 
    free(trimmed_line);
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
    int fd;
    char *line;
    int tokens_index;
    
    //game->map_started = 0;
    tokens_index = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error(game, "Couldn't open requested file.");
    while ((line = get_next_line(fd)))
    {
        printf("Linha lida: %s\n", line);
        process_line(game, line, &tokens_index);
        free(line);
    }
    if (!game->map_started)
        exit_error(game, "Error\nMap not found.\n");
    close(fd);
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
4. It checks if the number of parameters is valid.
*/
void tokenizer (t_game *game, char *file)
{
    int num_params;
    int count;
    int i = 0;

    num_params = 0;
    count = 0;

    split_file(game, file);
    i = 0;
    while (game->tokens_params[i])
        printf("Tokens: %s\n", game->tokens_params[i++]);
    i = 0;
    while (game->tokens_params[i])  
    {
        count++;
        i++;
    }
    if (count != 6)
        exit_error(game, "Invalid number of parameters.\n");
    // i = 0;
   // while (game->map.grid[i])
     //   printf("Mapa: %s\n", game->map.grid[i++]);
}
