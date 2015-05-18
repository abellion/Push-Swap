/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:56:59 by abellion          #+#    #+#             */
/*   Updated: 2015/02/25 15:17:20 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	printer_lst_nbr(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(*((int *)lst->content));
		if (lst->next)
			ft_putchar(' ');
		lst = lst->next;
	}
}

void	printer_lst_str(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		if (lst->next)
			ft_putchar(' ');
		lst = lst->next;
	}
}

void	printer_controller(t_list *operations, char *options)
{
	if (ft_strchr(options, 'd'))
		ft_putchar('\n');
	printer_operations(operations, options);
	if (ft_strchr(options, 'i'))
	{
		ft_putstr("\n\n");
		printer_infos(operations, options);
	}
	ft_putchar('\n');
}
