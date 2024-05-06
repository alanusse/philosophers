/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:07:55 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/06 14:33:57 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

/**
 * Initialize philos and forks variables.
 * If any of variables fails, free both and return 0, else return 1.
*/
static int	init_variables(t_philo ***philos, pthread_mutex_t **forks, int num_of_philos)
{
	init_philos(philos, num_of_philos);
	if (!*philos)
		return (0);
	init_forks(forks, num_of_philos);
	if (!*forks)
	{
		free_philos(philos, num_of_philos);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo					**philos;
	pthread_mutex_t	*forks;
	int							num_of_philos;

	if (!is_valid_arguments(argc, argv))
	{
		printf("%s\n", USAGE_MESSAGE);
		return (EXIT_FAILURE);
	}
	philos = NULL;
	forks = NULL;
	num_of_philos = ft_atoi(argv[1]);
	if(!init_variables(&philos, &forks, num_of_philos))
		return (EXIT_FAILURE);
	free_philos(&philos, num_of_philos);
	free_forks(&forks, num_of_philos);
	return (0);
}
