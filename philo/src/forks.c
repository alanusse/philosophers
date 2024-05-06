/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:59:58 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/06 13:58:47 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
