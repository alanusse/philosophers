/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:22:44 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/01 13:12:39 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define USAGE_MESSAGE "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>\n\
- number_of_philosophers: number greater than 0\n\
- time_to_die: number greater than 0 in milliseconds\n\
- time_to_eat: number greater than 0 in milliseconds\n\
- time_to_sleep: number greater than 0 in milliseconds\n\
- number_of_times_each_philosopher_must_eat: optional number\
greater than -1"

typedef struct s_philo
{
	pthread_t	*thread;
	int				id;
}							t_philo;

int	is_valid_arguments(int argc, char **argv);

#endif
