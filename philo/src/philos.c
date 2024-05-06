/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:58:29 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/06 14:06:41 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
 * Initialize philosophers.
 * Allocate an array containing each philosopher and each one has its own id.
 * If the allocation fails, iterate from the failed allocation to the start
 * freeing each philosopher.
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
