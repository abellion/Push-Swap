/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:56:59 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 19:09:59 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	pile_swap(t_list **lst)
{
	t_list		*first;
	t_list		*second;
	int			lst_len;

	lst_len = lst_count(*lst);
	first = lst_move_to(*lst, lst_len - 1);
	second = first->next;
	if (lst_len - 2)
		lst_move_to(*lst, lst_count(*lst) - 2)->next = second;
	else
		*lst = second;
	first->next = NULL;
	second->next = first;
}
