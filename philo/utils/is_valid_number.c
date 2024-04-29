/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:41:03 by aglanuss          #+#    #+#             */
/*   Updated: 2024/04/29 15:41:20 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_is_valid_number(char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0' || !ft_is_digit(*str))
		return (0);
	while (ft_is_digit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}
