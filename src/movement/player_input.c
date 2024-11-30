/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:58:36 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/21 13:15:14 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC
        game->keys.esc = 1;
    if (keycode == 119) // W
        game->keys.up = 1;
    if (keycode == 115) // S
        game->keys.down = 1;
    if (keycode == 97) // A
        game->keys.left = 1;
    if (keycode == 100) // D
        game->keys.right = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC
        game->keys.esc = 0;
    if (keycode == 119) // W
        game->keys.up = 0;
    if (keycode == 115) // S
        game->keys.down = 0;
    if (keycode == 97) // A
        game->keys.left = 0;
    if (keycode == 100) // D
        game->keys.right = 0;
    return (0);
}
