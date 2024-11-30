/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:57:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/21 13:13:50 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void setup_textures(t_game *game)
{
    game->textures[0].img = mlx_xpm_file_to_image(game->mlx, "textures/north.xpm", &game->textures[0].width, &game->textures[0].height);
    game->textures[1].img = mlx_xpm_file_to_image(game->mlx, "textures/south.xpm", &game->textures[1].width, &game->textures[1].height);
    game->textures[2].img = mlx_xpm_file_to_image(game->mlx, "textures/east.xpm", &game->textures[2].width, &game->textures[2].height);
    game->textures[3].img = mlx_xpm_file_to_image(game->mlx, "textures/west.xpm", &game->textures[3].width, &game->textures[3].height);
}
