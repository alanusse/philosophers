/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:47:26 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/22 14:10:17 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

void  philo_eat(t_philo **philo)
{
  pthread_mutex_lock(&(*philo)->left_fork);
  printf("%zi %i has taken a fork\n", get_current_time(), (*philo)->id);
  pthread_mutex_lock(&(*philo)->rigth_fork);
  printf("%zi %i has taken a fork\n", get_current_time(), (*philo)->id);
  printf("%zi %i is eating\n", get_current_time(), (*philo)->id);
  ft_usleep((*(*philo)->time_to_eat));
  (*philo)->last_meal = get_current_time(); // todo: set last meal timestamp
  (*philo)->eat_times += 1;
  pthread_mutex_unlock(&(*philo)->left_fork);
  pthread_mutex_unlock(&(*philo)->rigth_fork);
}

void philo_sleep(t_philo **philo)
{
  printf("%zi %i is sleeping\n", get_current_time(), (*philo)->id);
  ft_usleep((*(*philo)->time_to_sleep));
}

void philo_think(t_philo **philo)
{
  printf("%zi %i is thinking\n", get_current_time(), (*philo)->id);
}
