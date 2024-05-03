/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:07:55 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/03 13:39:58 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

int	main(int argc, char **argv)
{
	t_philo					**philos;
	pthread_mutex_t			*forks;
	int						num_of_philos;

	if (!is_valid_arguments(argc, argv))
	{
		printf("%s\n", USAGE_MESSAGE);
		return (EXIT_FAILURE);
	}
	philos = NULL;
	forks = NULL;
	num_of_philos = ft_atoi(argv[1]);
	if (!init_philos(&philos, num_of_philos))
	{
		free_philos(&philos);
		// free_forks(&forks);
		return (EXIT_FAILURE);
	}
	// int i = -1;
	// while (++i < num_of_philos)
	// {
	// 	printf("philo id: %i\n", philos[i]->id);
	// }
	free_philos(&philos);
	// free_forks(&forks);
	return (0);
}
