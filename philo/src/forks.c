/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:59:58 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/29 14:02:15 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void  unlock_forks(pthread_mutex_t **forks, int num_of_forks)
{
  int i;

  i = 0;
  while (i < num_of_forks)
  {
    pthread_mutex_unlock(&(*forks)[i]);
    i++;
  }
}

/**
 * Frees an array of mutexes (forks) and destroys each mutex.
 * Assumes that all mutexes were previously initialized.
 * Iterates through each mutex, destroying them individually before freeing
 * the entire array and setting the pointer to NULL to prevent dangling
 * pointer usage.
 * 
 * @param forks Pointer to the array of mutexes to be freed.
 * @param num_of_forks Number of mutexes in the array.
 */
void  free_forks(pthread_mutex_t **forks, int num_of_forks)
{
  int i;

  i = -1;
  if (!*forks)
    return ;
  while (forks[++i] && i < num_of_forks)
    pthread_mutex_destroy(&(*forks)[i]);
  free(*forks);
  *forks = NULL;
}

/**
 * Initializes and allocates memory for an array of mutexes (forks).
 * Each mutex is initialized individually. 
 * If any initialization fails, all previously initialized mutexes are
 * destroyed to ensure proper cleanup, and the memory for the array is freed,
 * setting the pointer to NULL to prevent future use.
 * This ensures robust error handling and proper resource
 * cleanup in case of failure.
 * 
 * @param forks Pointer to the array of mutexes to be initialized.
 * @param num_of_forks Number of mutexes to initialize in the array.
 */
void  init_forks(pthread_mutex_t **forks, int num_of_forks)
{
  int i;

  i = -1;
  *forks = malloc(sizeof(pthread_mutex_t) * num_of_forks);
  if (!*forks)
    return ;
  while (++i < num_of_forks)
  {
    if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
    {
      while (--i >= 0)
        pthread_mutex_destroy(&(*forks)[i]);
      free(*forks);
      *forks = NULL;
      return ;
    }
  }
}
