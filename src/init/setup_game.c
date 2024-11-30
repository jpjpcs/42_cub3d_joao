/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:57:27 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/30 18:23:15 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void setup_game(t_game *game)
{
    game->screen_width = SCREEN_WIDTH;
    game->screen_height = SCREEN_HEIGHT;
    
    game->player.x = 2.0; // Posição inicial do jogador no eixo X
    game->player.y = 2.0; // Posição inicial do jogador no eixo Y
    game->player.dir_x = -1.0; // Direção inicial no eixo X
    game->player.dir_y = 0.0; // Direção inicial no eixo Y
    game->player.plane_x = 0.0; // Plano de câmera X
    game->player.plane_y = 0.66; // Plano de câmera Y
    game->player.move_speed = MOVE_SPEED;
    game->player.rot_speed = ROT_SPEED;

    game->keys.up = 0;
    game->keys.down = 0;
    game->keys.left = 0;
    game->keys.right = 0;
    game->keys.esc = 0;
}
