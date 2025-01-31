/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:38:35 by rzvir             #+#    #+#             */
/*   Updated: 2025/01/31 15:30:58 by rzvir            ###   ########.fr       */
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

typedef struct s_philosopher_forks
{
	t_fork	*left_fork;
	t_fork	*right_fork;
}	t_philosopher_forks;

typedef struct s_philosopher
{
	int					number_of_meals;
	unsigned int		philosopher_number;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	pthread_t			thread;
	t_philosopher_forks	forks;
}	t_philosopher;
typedef struct s_monitor
{
	unsigned int	is_someone_dead;
	t_fork			**forks;
	t_philosopher	**philosophers;
}	t_monitor;

typedef struct s_philo_info
{
	t_philosopher	*philo;
	unsigned int	*is_someone_dead;
}	t_philo_info;


size_t				ft_nbrlen(int n);
size_t				ft_strlen(const char *s);
unsigned int		ft_atoui(const char *nptr);
unsigned long long	ft_atoull(const char *nptr);

int					show_help(void);
int					show_error(int code);

int					is_invalid_argument(char *argument);
int					validate_arguments(int argc, char **argv);

#endif