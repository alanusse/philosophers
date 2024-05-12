/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:58:29 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/12 12:46:49 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Frees an array of philosophers, ensuring each philosopher's structure
 * is freed and then the entire array itself.
 * It sets each philosopher pointer to NULL after freeing to prevent dangling
 * references. The function checks if the pointer to the array is not NULL
 * before proceeding and iterates up to the specified number of philosophers.
 *
 * @param philos Pointer to the array of philosopher pointers to be freed.
 * @param num_of_philos Number of philosopher pointers in the array.
 */
void	free_philos(t_philo ***philos, int num_of_philos)
{
	int	i;

	i = -1;
	if (!*philos)
		return;
	while ((*philos)[++i] && i < num_of_philos)
	{
		free((*philos)[i]);
		(*philos)[i] = NULL;
	}
	free(*philos);
	*philos = NULL;
}

/**
 * Assigns forks to philosophers in a circular dining arrangement to
 * prevent deadlock. For the first philosopher, the right fork is
 * the last in the array and the left fork is the first.
 * For all other philosophers, the right fork is immediately to
 * their left, and their left fork is at their own index.
 *
 * @param philos Triple pointer to the array of philosopher structures.
 * @param forks Double pointer to the array of mutexes representing forks.
 * @param index Index of the current philosopher.
 * @param num_of_philos Total number of philosophers.
 */
static void set_forks(t_philo ***philos, pthread_mutex_t **forks, int index,
  int num_of_philos)
{
  if (index == 0)
  {
    (*philos)[index]->rigth_fork = forks[num_of_philos - 1];
    (*philos)[index]->left_fork = forks[0];
  }
  else
  {
    (*philos)[index]->rigth_fork = forks[index - 1];
    (*philos)[index]->left_fork = forks[index];
  }
}

/**
 * Initializes an array of pointers to t_philo structures, allocating memory
 * for each philosopher and setting their IDs. If any allocation fails during
 * the initialization, it frees all previously allocated memory to avoid
 * memory leaks, using the free_philos function.
 * Each philosopher pointer is initially set to NULL before memory allocation
 * to ensure safe cleanup in case of failure.
 *
 * @param philos Pointer to the array of philosopher pointers to be initialized.
 * @param num_of_philos Number of philosophers to initialize in the array.
 */
void init_philos(t_philo ***philos, pthread_mutex_t **forks, int num_of_philos)
{
	int i;

	*philos = malloc(sizeof(t_philo *) * num_of_philos);
	if (!*philos)
		return;
	i = -1;
	while (++i < num_of_philos)
		(*philos)[i] = NULL;
	i = -1;
	while (++i < num_of_philos)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
		{
			free_philos(philos, num_of_philos);
			return;
		}
		(*philos)[i]->id = i + 1;
    set_forks(philos, forks, i, num_of_philos);
	}
}
