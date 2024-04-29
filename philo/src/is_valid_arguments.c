/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:05:31 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/29 18:09:25 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include "../includes/utils.h"

int	is_valid_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!ft_is_valid_number(argv[1]) || ft_atoi(argv[1]) < 1
		|| !ft_is_valid_number(argv[2]) || ft_atoi(argv[2]) < 1
		|| !ft_is_valid_number(argv[3]) || ft_atoi(argv[3]) < 1
		|| !ft_is_valid_number(argv[4]) || ft_atoi(argv[4]) < 1
		|| (argc == 6 && (!ft_is_valid_number(argv[5]) || ft_atoi(argv[5]) < 0)))
		return (0);
	else
		return (1);
}
