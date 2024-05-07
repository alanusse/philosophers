/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:58:29 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/07 12:46:33 by aglanuss         ###   ########.fr       */
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
void  free_philos(t_philo ***philos, int num_of_philos)
{
  int i;

  i = -1;
  if (!*philos)
    return ;
  while ((*philos)[++i] && i < num_of_philos)
  {
    free((*philos)[i]);
    (*philos)[i] = NULL;
  }
  free(*philos);
  *philos = NULL;
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
void  init_philos(t_philo ***philos, int num_of_philos)
{
	int i;

	*philos = malloc(sizeof(t_philo *) * num_of_philos);
  if (!*philos)
    return ;
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
      return ;
    }
		(*philos)[i]->id = i + 1;
	}
}
