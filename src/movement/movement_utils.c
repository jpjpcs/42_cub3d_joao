/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:03 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/30 18:59:55 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void move_forward(t_game *game)
{
    game->player.x += game->player.dir_x * game->player.move_speed;
    game->player.y += game->player.dir_y * game->player.move_speed;
}

void move_backward(t_game *game)
{
    game->player.x -= game->player.dir_x * game->player.move_speed;
    game->player.y -= game->player.dir_y * game->player.move_speed;
}

void strafe_left(t_game *game)
{
    game->player.x -= game->player.plane_x * game->player.move_speed;
    game->player.y -= game->player.plane_y * game->player.move_speed;
}

void strafe_right(t_game *game)
{
    game->player.x += game->player.plane_x * game->player.move_speed;
    game->player.y += game->player.plane_y * game->player.move_speed;
}