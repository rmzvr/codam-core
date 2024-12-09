/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:01 by rzvir             #+#    #+#             */
/*   Updated: 2024/12/09 12:35:06 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_set_name(char *curr_set_name)
{
	if (!ft_strncmp(curr_set_name, SET_MB_JL, ft_strlen(SET_MB_JL))
		|| !ft_strncmp(curr_set_name, SET_MB, ft_strlen(SET_MB))
		|| !ft_strncmp(curr_set_name, SET_JL, ft_strlen(SET_JL)))
	{
		return (1);
	}
	return (0);
}

void	handle_required_arguments(int argc, char **argv, t_mlx *mlx)
{
	if (ft_strncmp(mlx->curr_set_name, SET_JL, ft_strlen(SET_JL)) == 0)
	{
		if (argc >= 4 && is_valid_double(argv[2]) && is_valid_double(argv[3]))
		{
			mlx->j_re = ft_atof(argv[2]);
			mlx->j_im = ft_atof(argv[3]);
		}
		else
		{
			cleanup(mlx, 0);
			show_help_and_exit();
		}
	}
}

static void	validate_optional_argument(char **arg, t_mlx *mlx)
{
	if (arg[1] == NULL)
	{
		free(arg[0]);
		free(arg);
		cleanup(mlx, 0);
		show_help_and_exit();
	}
}

static void	apply_optional_arguments(t_mlx *mlx, char *curr_arg)
{
	char	**arg;
	char	*arg_name;
	char	*arg_value;

	arg = ft_split(curr_arg, '=');
	validate_optional_argument(arg, mlx);
	arg_name = arg[0];
	if (ft_strlen(curr_arg) == ft_strlen(arg_name))
		show_help_and_exit();
	arg_value = arg[1];
	if (ft_strncmp(arg_name, "--width", ft_strlen(arg_name)) == 0)
		mlx->ww = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--height", ft_strlen(arg_name)) == 0)
		mlx->wh = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--iterations", ft_strlen(arg_name)) == 0)
		mlx->max_iterations = ft_atoi(arg_value);
	else if (ft_strncmp(arg_name, "--zoom", ft_strlen(arg_name)) == 0)
		mlx->scale_factor = ft_atof(arg_value);
	else if (ft_strncmp(arg_name, "--palette", ft_strlen(arg_name)) == 0)
		mlx->palette = arg_value;
	else
	{
		cleanup(mlx, 0);
		show_help_and_exit();
	}
}

void	handle_optional_arguments(int argc, char **argv, t_mlx *mlx)
{
	int	i;

	if (ft_strncmp(mlx->curr_set_name, SET_JL, ft_strlen(SET_JL)) == 0)
		i = 4;
	else
		i = 2;
	if (argc > i)
	{
		while (i <= argc - 1)
		{
			apply_optional_arguments(mlx, argv[i]);
			i++;
		}
	}
}
