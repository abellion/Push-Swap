/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:24 by abellion          #+#    #+#             */
/*   Updated: 2015/02/25 15:16:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	printer_details(t_piles *piles, char *operation, char *options)
{
	static int		first_time;

	if (!first_time && ft_strchr(options, 'v'))
	{
		ft_putstr("### CHANGEMENTS EFFECTUES ###\n");
		first_time = 1;
	}
	ft_putstr(operation);
	ft_putstr(" -> [");
	if (ft_strchr(operation, 'a'))
		printer_lst_nbr(piles->a);
	else
		printer_lst_nbr(piles->b);
	ft_putstr("]\n");
}
