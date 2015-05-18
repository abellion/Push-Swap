/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:06 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:57:07 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	printer_infos(t_list *operations, char *options)
{
	if (ft_strchr(options, 'v'))
		ft_putstr("### INFORMATIONS ###\n");
	ft_putstr("Nombre d'operations : ");
	ft_putnbr(lst_count(operations));
}
