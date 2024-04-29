/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:38:06 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/29 15:38:37 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_strlen(char *str)
{
	int	count;

	if (!str || !*str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}
