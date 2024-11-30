/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:03 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/21 13:15:14 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void move_forward(t_game *game)
{
    game->player.pos_x += game->player.dir_x * game->player.move_speed;
    game->player.pos_y += game->player.dir_y * game->player.move_speed;
}

void move_backward(t_game *game)
{
    game->player.pos_x -= game->player.dir_x * game->player.move_speed;
    game->player.pos_y -= game->player.dir_y * game->player.move_speed;
}

void strafe_left(t_game *game)
{
    game->player.pos_x -= game->player.plane_x * game->player.move_speed;
    game->player.pos_y -= game->player.plane_y * game->player.move_speed;
}

void strafe_right(t_game *game)
{
    game->player.pos_x += game->player.plane_x * game->player.move_speed;
    game->player.pos_y += game->player.plane_y * game->player.move_speed;
}