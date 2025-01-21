/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:53 by rmzvr             #+#    #+#             */
/*   Updated: 2025/01/20 23:41:58 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <aio.h>
#include <signal.h>

int	main(void)
{
	int		i;
	int		mask;
	char	*message;
	char	character;
	char	iteration;
	pid_t	process_id;

	i = 0;
	mask = 128;
	message = ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sodales lacus et tellus mollis, in interdum arcu accumsan. Vivamus sit amet rutrum ipsum. Proin bibendum finibus congue. Maecenas diam ex, porta quis congue vel, auctor porttitor justo. Quisque congue ligula libero, non placerat metus pharetra sed. Cras lacinia tortor a purus interdum sagittis. Mauris a magna nisl. Suspendisse quis nulla ac lectus vulputate malesuada id vitae dui. Nam ac sem faucibus, interdum nunc at, dapibus ex. Vestibulum mattis cursus mollis. Ut rhoncus sollicitudin gravida.\n");
	process_id = getpid();
	ft_printf("The client ID is %d\n", process_id);
	while (message[i] != '\0')
	{
		iteration = 0;
		character = message[i];
		while (iteration < 8)
		{
			if (character & mask)
			{
				kill(550716, SIGUSR2);
			}
			else
			{
				kill(550716, SIGUSR1);
			}
			usleep(2000);
			iteration++;
			character <<= 1;
		}
		i++;
	}
	return (0);
}
