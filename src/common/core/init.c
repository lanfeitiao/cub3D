/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 15:59:19 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/10 15:22:34 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "control.h"
#include "render.h"

static void	init_asset(t_asset *asset)
{
	asset->no_path = NULL;
	asset->so_path = NULL;
	asset->we_path = NULL;
	asset->ea_path = NULL;
	asset->door_path = NULL;
	asset->floor.r = -1;
	asset->floor.g = -1;
	asset->floor.b = -1;
	asset->ceiling.r = -1;
	asset->ceiling.g = -1;
	asset->ceiling.b = -1;
	asset->no_img = NULL;
	asset->so_img = NULL;
	asset->we_img = NULL;
	asset->ea_img = NULL;
	asset->door_img = NULL;
	init_animated_sprite_in_asset(asset);
}

void	init_game_state(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	init_asset(&game->asset);
	init_player(&game->player);
	init_map(&game->map);
	init_minimap(&game->minimap);
	ft_bzero(game->rays, sizeof(game->rays));
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game->mlx)
		ft_mlx_error(game);
}

void	init_input_system(t_game *game)
{
	mlx_key_hook(game->mlx, &handle_key_press, game);
	mlx_cursor_hook(game->mlx, &handle_mouse_move, game);
	mlx_close_hook(game->mlx, &handle_window_close, game);
}
