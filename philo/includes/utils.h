/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:27:38 by aglanuss          #+#    #+#             */
/*   Updated: 2024/05/18 20:11:23 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

int ft_strlen(char *str);
int ft_is_digit(char c);
int ft_is_valid_number(char *str);
int ft_atoi(const char *str);
int	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

#endif
