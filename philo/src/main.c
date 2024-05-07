/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:07:55 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/07 12:59:55 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

/**
 * Initializes a program structure with values from command line arguments.
 * This includes allocating and setting up associated philosophers and forks
 * based on the given number of philosophers. The function handles memory
 * allocation failures by cleaning up any partially allocated resources and
 * ensures that the program pointer is set to NULL to prevent
 * dangling pointers. This function has no return value but ensures that the
 * program is either fully initialized or completely cleaned up with the
 * program pointer set to NULL on failure.
 * 
 * @param argc The count of command line arguments.
 * @param argv The array of command line arguments.
 * @param program A pointer to the pointer of the program
 * structure to initialize.
 */
static void	init_program(int argc, char **argv, t_program **program)
{
	*program = malloc(sizeof(t_program));
	if (!*program)
		return ;
	(*program)->num_of_philos = ft_atoi(argv[1]);
	(*program)->time_to_die = ft_atoi(argv[2]);
	(*program)->time_to_eat = ft_atoi(argv[3]);
	(*program)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*program)->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	init_philos(&(*program)->philos, (*program)->num_of_philos);
	if (!(*program)->philos)
	{
		free(*program);
		*program = NULL;
		return ;
	}
	init_forks(&(*program)->forks, (*program)->num_of_philos);
	if (!(*program)->forks)
	{
		free_philos(&(*program)->philos, (*program)->num_of_philos);
		free(*program);
		*program = NULL;
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_program				*program;

	if (!is_valid_arguments(argc, argv))
	{
		printf("%s\n", USAGE_MESSAGE);
		return (EXIT_FAILURE);
	}
	program = NULL;
	init_program(argc, argv, &program);
	if(!program)
		return (EXIT_FAILURE);
	free_philos(&program->philos, program->num_of_philos);
	free_forks(&program->forks, program->num_of_philos);
	free(program);
	return (0);
}
