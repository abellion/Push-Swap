/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:57:17 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:57:19 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	printer_operations(t_list *operations, char *options)
{
	if (ft_strchr(options, 'v'))
		ft_putstr("### OPERATIONS ###\n");
	printer_lst_str(operations);
}
