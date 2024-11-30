/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:57:39 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/21 13:15:14 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void setup_mlx(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "Cub3D");
    game->img = mlx_new_image(game->mlx, game->screen_width, game->screen_height);
}
