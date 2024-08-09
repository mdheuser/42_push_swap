/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahlstr <mdahlstr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:34:43 by mdahlstr          #+#    #+#             */
/*   Updated: 2024/04/29 13:04:49 by mdahlstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= '0') && (c <= '9'))
		|| ((c >= 'A') && (c <= 'Z'))
		|| ((c >= 'a') && (c <= 'z')))
		return (1);
	else
		return (0);
}
