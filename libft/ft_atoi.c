/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:38:06 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/08/08 22:13:17 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\t') || (c == '\r')
		|| (c == '\n') || (c == '\v') || (c == '\f'));
}

int	ft_atoi(const char *str, bool *overflow)
{
	long int	num;
	long int	buffer;
	int			sign;

	num = 0;
	sign = 1;
	overflow = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		buffer = num;
		num = num * 10 + (*str - '0');
		if (num / 10 != buffer && sign == -1)
			return (0);
		else if (num / 10 != buffer && sign == 1)
			return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
        num = num * 10 + (*str - '0');
        if (num > INT_MAX) { // Check for overflow
            *overflow = true;
            return (0); // Return 0 or any sentinel value
        }
        str++;
    }
	return ((int)(num * sign));
}