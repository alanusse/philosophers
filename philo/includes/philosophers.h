/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:22:44 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/23 13:05:27 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define USAGE_MESSAGE "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>\n\
- number_of_philosophers: number greater than 0\n\
- time_to_die: number greater than 0 in milliseconds\n\
- time_to_eat: number greater than 0 in milliseconds\n\
- time_to_sleep: number greater than 0 in milliseconds\n\
- number_of_times_each_philosopher_must_eat: optional number\
greater than -1"

typedef struct s_philo
{
	int							id;
	pthread_t				thread;
  pthread_mutex_t rigth_fork;
  pthread_mutex_t left_fork;
  int             *philo_died;
	int							eat_times;
	size_t					last_meal;
	size_t					*time_to_die; // todo: change without pointer
	int							*time_to_eat; // todo: change without pointer
	size_t					*time_to_sleep; // todo: change without pointer
	int							*number_of_times_each_philosopher_must_eat; // todo: change without pointer
}							t_philo;

typedef struct s_program
{
	t_philo					**philos;
	pthread_mutex_t	*forks;
  pthread_t       died_monitor;
	int							num_of_philos;
  int             philo_died;
	size_t					time_to_die;
	int							time_to_eat;
	size_t					time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
}							t_program;

void	init_philos(t_program **program, t_philo ***philos, pthread_mutex_t *forks, int num_of_philos);
void	free_philos(t_philo ***philos, int num_of_philos);
int   philo_eat(t_philo **philo);
int 	philo_sleep(t_philo **philo);
int 	philo_think(t_philo **philo);
void	start_philos_routine(t_program **program);
int   is_philo_died(t_philo **philo);

void	init_forks(pthread_mutex_t **forks, int num_of_forks);
void	free_forks(pthread_mutex_t **forks, int num_of_forks);

int   is_valid_arguments(int argc, char **argv);

#endif
