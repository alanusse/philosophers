/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:07:55 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/02 23:37:00 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

int	init_philos(t_philo **philos, int num_of_philos)
{
	int	i;

	philos = malloc(sizeof(t_philo *) * num_of_philos);
	i = -1;
	while (++i < num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->id = i + 1;
		philos[i]->thread = malloc(sizeof(pthread_t *));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	**philos;

	if (!is_valid_arguments(argc, argv))
	{
		printf("%s\n", USAGE_MESSAGE);
		return (EXIT_FAILURE);
	}
	philos = NULL;
	init_philos(philos, ft_atoi(argv[1]));

	int i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		printf("philo id: %i\n", philos[i]->id);
	}
	return (0);
}