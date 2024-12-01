/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:17 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/01 17:12:01 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
//# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# elif defined(__APPLE__)
#  include "../minilibx_opengl_20191021/mlx.h"
# endif

// ------------ Tiles ------------
# define TILES "01NSEW"
# define O_XPM "textures/1.xpm"
# define Z_XPM "textures/0.xpm"
# define N_XPM "textures/N.xpm"
# define S_XPM "textures/S.xpm"
# define E_XPM "textures/E.xpm"
# define W_XPM "textures/W.xpm"

// ------------ Macros ------------
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// ------------ Structs ------------

typedef enum e_tile
{
	WALL = '1',
	SPACE = '0',
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
    EAST = 'E',
}				t_tile;

// Map struct
typedef struct s_map 
{
    char **grid; // Map data: 2D array of characters. Each character represents a different element of the map. 
    int rows; // map_height 
    int cols; // map_width
} t_map;

// Keys struct
typedef struct s_keys 
{
    int up;
    int down;
    int left;
    int right;
    int esc;
    int rotate_left;
    int rotate_right;
} t_keys;

// Texture struct
typedef struct s_texture 
{
    void *img; // Image of the texture itself.
    char *path; // address of the texture file.;
    int width;
    int height;
} t_texture;

// Player struct
typedef struct s_player 
{
    double x; // Player´s X position
    double y; // Player´s Y position
    double dir_x; // Player´s direction vector X
    double dir_y; // Player´s direction vector Y
    double plane_x; // Player´s camera plane X
    double plane_y; // Player´s camera plane Y
    float move_speed; // Player´s movement speed
    float rot_speed; // Player´s rotation speed
} t_player;

// Main game struct
typedef struct s_game 
{
    // MLX variables (graphic library)
    void *mlx; // Instance of the mlx library. To allow interaction with the graphic system.
    void *win; // Game window to be rendered. The window where the game will be displayed.
    void *img; // Image to be rendered. The image that will be displayed on the window and that´s the background of the game.

    // Game Map (2D representation)
    t_map map; // The Map of the game: map structure. Contains the map data and its dimensions (width and height).
    int map_started; // Flag to check if we have reached the map content. If the map has started.
    char *tokens_params[6]; // Array with the splited map parameters.
    char *tmp_map_grid; // Temporary map grid to store the map data before it´s copied to the map structure.
    // Players properties
    t_player player; // Player´s information: position, direction, etc
    
    // Game controls
    t_keys keys; // Keys controls: up, down, left, right arrows and ESC. 
    
    // Textures
    t_texture textures[4]; // Texture for the 4 directions for walls and sprites: north, south, east, west, amd the player.
    //t_texture		img_walls;
	//t_texture		img_player;
    
    // Colors
    int floor_color;
    int ceiling_color;
    
    // Screen size
    int screen_width; // Screen/Window width and height.
    int screen_height;
} t_game;

// ------------ Prototypes ------------
//void init_game(t_game *game);
//void render_game(t_game *game);
//void handle_keys(t_game *game);
//void move_player(t_game *game);
//void load_textures(t_game *game);

//Parser
void tokenizer (t_game *game, char *file);
void lexer(t_game *game);
void parse_check_map(t_game *game, char *file);

//Init
void setup_game(t_game *game);
void setup_mlx(t_game *game);
void setup_textures(t_game *game);

// ------------ Key Hooks ------------
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);

//Movement
void move_forward(t_game *game);
void move_backward(t_game *game);
void strafe_left(t_game *game);
void strafe_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);

//Rendering
void draw(t_game *game);
void raycast(t_game *game);
void draw_textures(t_game *game);

//Cleanup - exit/error
void exit_error (t_game *game, char *msg);
int	exit_game(t_game *game, char *msg);
int	exit_esc(t_game *game);
void	free_game(t_game *game);

// ------------ Error Handling ------------
int error_exit(const char *msg);

#endif

/*
cub3d/
├── include/
│   ├── cub3d.h
│   ├── parser.h
│   ├── game.h
│   ├── movement.h
│   ├── rendering.h
│   └── cleanup.h
├── src/
│   ├── main.c
│   ├── parser/
│   │   ├── config.c
│   │   ├── map_loader.c
│   │   └── validation.c
│   ├── init/
│   │   ├── setup_game.c
│   │   ├── setup_mlx.c
│   │   └── setup_textures.c
│   ├── movement/
│   │   ├── player_input.c
│   │   ├── movement_utils.c
│   │   └── rotation.c
│   ├── rendering/
│   │   ├── draw.c
│   │   ├── raycasting.c
│   │   └── textures.c
│   ├── cleanup/
│   │   ├── free_resources.c
│   │   └── exit_game.c


cub3d/
├── include/
│   ├── cub3d.h
├── src/
│   ├── main.c
│   ├── parser/
│   │   ├── config.c
│   │   ├── map_loader.c
│   │   └── validation.c
│   ├── init/
│   │   ├── setup_game.c
│   │   ├── setup_mlx.c
│   │   └── setup_textures.c
│   ├── movement/
│   │   ├── player_input.c
│   │   ├── movement_utils.c
│   │   └── rotation.c
│   ├── rendering/
│   │   ├── draw.c
│   │   ├── raycasting.c
│   │   └── textures.c
│   ├── cleanup/
│   │   ├── free_resources.c
│   │   └── exit_game.c
*/
