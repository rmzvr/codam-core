/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:38:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/27 21:19:03 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				taken;
}	t_fork;

typedef struct s_philosopher
{
	pthread_t			thread;
	int					philosopher_number;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					number_of_meals;
}	t_philosopher;
typedef struct s_monitor
{
	t_fork			**forks;
	t_philosopher	**philosophers;
}	t_monitor;

size_t				ft_nbrlen(int n);
size_t				ft_strlen(const char *s);
unsigned int		ft_atoui(const char *nptr);
unsigned long long	ft_atoull(const char *nptr);

int					show_help(void);
int					show_error(int code);

int					is_invalid_argument(char *argument);
int					validate_arguments(int argc, char **argv);

#endif