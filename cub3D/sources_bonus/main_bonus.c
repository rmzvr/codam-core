/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:12:09 by rmzvr             #+#    #+#             */
/*   Updated: 2025/07/24 14:00:33 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "state_bonus.h"
#include "parser/parser_bonus.h"

static
bool	initialize_run_game(t_game_state *state, t_root *root)
{
	state->player.map = root->map;
	state->ceiling = root->ceiling_c;
	state->floor = root->floor_c;
	if (!initialize_window_and_image(&state->mlx))
	{
		ft_dprintf(2, "Error\n%s: failed to initialize window\n",
			PROGRAM_NAME);
		return (false);
	}
	initialize_player(&state->player);
	if (!initialize_textures(root, &state->textures, &state->mlx))
	{
		if (errno != 0)
			ft_dprintf(2, "Error\n%s: failed to initialize textures: %s\n",
				PROGRAM_NAME, strerror(errno));
		else
			ft_dprintf(2, "Error\n%s: failed to initialize textures\n",
				PROGRAM_NAME);
		return (false);
	}
	initialize_hooks(state);
	mlx_loop(state->mlx.ptr);
	return (true);
}

static
t_root	*parse_buffer_root(t_parser *parser)
{
	t_root	*root;

	root = parser_parse(parser);
	if (!parser_validate_root(parser, root))
	{
		if (parser->error != NULL)
			ft_dprintf(2, "Error\n%s: parser error: %s\n", PROGRAM_NAME,
				parser->error);
		else
			ft_dprintf(2, "Error\n%s: failed to parse map\n", PROGRAM_NAME);
		parser_destroy_root(root);
		root = NULL;
	}
	return (root);
}

static
t_root	*parse_file_buffer(const char *buffer)
{
	t_lexer		*lexer;
	t_parser	*parser;
	t_root		*root;

	lexer = lexer_create(buffer);
	if (lexer == NULL || !lexer_tokenize(lexer))
	{
		ft_dprintf(2, "Error\n%s: failed to tokenize buffer\n", PROGRAM_NAME);
		lexer_destroy(lexer);
		return (NULL);
	}
	parser = parser_create(lexer);
	if (parser == NULL)
	{
		ft_dprintf(2, "Error\n%s: failed to create parser\n", PROGRAM_NAME);
		lexer_destroy(lexer);
		return (NULL);
	}
	root = parse_buffer_root(parser);
	lexer_destroy(lexer);
	parser_destroy(parser);
	return (root);
}

static
t_root	*parse_file_root(const char *filename)
{
	char	*buffer;
	t_root	*root;

	buffer = read_file(filename);
	if (buffer == NULL)
	{
		if (errno != 0)
			ft_dprintf(2, "Error\n%s: failed to read file: %s\n",
				PROGRAM_NAME, strerror(errno));
		else
			ft_dprintf(2, "Error\n%s: failed to parse: map is empty\n",
				PROGRAM_NAME);
		return (NULL);
	}
	root = parse_file_buffer(buffer);
	free(buffer);
	return (root);
}

int	main(int argc, char *argv[])
{
	t_root			*root;
	t_game_state	state;
	bool			ran_game;

	if (argc != 2 || !ft_endswith(argv[1], FILENAME_EXTENSION))
	{
		ft_dprintf(2, "Error\n%s: invalid argument\n"
			"usage: ./%s <filename> - filename must end with %s\n",
			PROGRAM_NAME, PROGRAM_NAME, FILENAME_EXTENSION);
		return (EXIT_FAILURE);
	}
	root = parse_file_root(argv[1]);
	if (root == NULL)
		return (EXIT_FAILURE);
	ft_bzero(&state, sizeof(t_game_state));
	ran_game = initialize_run_game(&state, root);
	cleanup_game_state(&state);
	parser_destroy_root(root);
	if (ran_game)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
