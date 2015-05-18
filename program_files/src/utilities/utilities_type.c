/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:25:23 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:55:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

int		is_number(char *str)
{
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str && ft_isdigit(*str))
		str++;
	return ((!*str) ? 1 : 0);
}

int		is_integer(char *str)
{
	int		nb;

	nb = ft_atoi(str);
	if (nb < 0 && str[0] != '-')
		return (0);
	return (1);
}
