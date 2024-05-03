/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:58:29 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/03 13:40:28 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void  free_philos(t_philo ***philos)
{
  int i;

  i = -1;
  if (!*philos)
    return ;
  while ((*philos)[++i])
    free((*philos)[i]);
  free(*philos);
  *philos = NULL;
}

/**
 * Initialize philosophers.
 * Allocate an array containing each philosopher and each one has its own id.
 * If the allocation fails, iterate from the failed allocation to the start
 * freeing each philosopher.
*/
int	init_philos(t_philo ***philos, int num_of_philos)
{
	int i;

	*philos = malloc(sizeof(t_philo *) * num_of_philos);
  if (!*philos)
    return (0);
	i = -1;
	while (++i < num_of_philos)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
    if (!(*philos)[i])
    {
      while (--i >= 0)
        free((*philos)[i]);
      *philos = NULL;
      return (0);
    }
		(*philos)[i]->id = i + 1;
	}
	return (1);
}
