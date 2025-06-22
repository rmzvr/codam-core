/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:49:55 by kvalerii          #+#    #+#             */
/*   Updated: 2025/04/25 13:39:02 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signal_handler.h"
#include "builtins/builtins.h"
#include "exec_cmd/exec_cmd.h"
#include "utils.h"

sig_atomic_t	g_is_interactive_mode_switch;

t_data	initialize_minishell_data(
	char **envp
)
{
	t_data	data;

	data.envp = envp;
	data.argv = NULL;
	data.count_lines = 0;
	data.last_exit_code = 0;
	data.tokens = NULL;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		data.isatty = TRUE;
	}
	else
	{
		data.isatty = FALSE;
	}
	data.home = NULL;
	data.user_hostname = NULL;
	data.tree.type.command = NULL;
	return (data);
}

static int	check_shlvl_limit(
	char ***envp
)
{
	char	*current_shlvl_str;
	int		current_shlvl;

	current_shlvl_str = ft_getenv(*envp, "SHLVL");
	if (current_shlvl_str == NULL || ft_check_num(current_shlvl_str) == FALSE)
	{
		if (ft_putenv(envp, "SHLVL=1") == EMALLOC)
		{
			return (EMALLOC);
		}
		return (0);
	}
	current_shlvl = ft_atoi(current_shlvl_str);
	if (current_shlvl >= 1000)
	{
		ft_dprintf(STDOUT_FILENO, "bash: warning: shell level "
			"(%d) too high, resetting to 1\n", current_shlvl);
		if (ft_putenv(envp, "SHLVL=1") == EMALLOC)
		{
			return (EMALLOC);
		}
		return (0);
	}
	return (0);
}

static char	**get_custom_envp(int argc, char **argv, char **envp)
{
	char	**_envp;

	(void) argv;
	(void) argc;
	_envp = copy_char_array(envp, ft_char_array_len(envp));
	if (_envp == NULL)
	{
		ft_putendl_fd(MEMERR, STDERR_FILENO);
		return (NULL);
	}
	return (_envp);
}

int	main(
	int argc,
	char **argv,
	char **envp
)
{
	char	**_envp;
	t_data	data;

	_envp = get_custom_envp(argc, argv, envp);
	if (_envp == NULL)
	{
		return (2);
	}
	if (check_shlvl_limit(&_envp) == EMALLOC)
	{
		ft_free_double_char_pointer(&_envp);
		return (2);
	}
	data = initialize_minishell_data(_envp);
	run_readline(&data);
	return (OK);
}
