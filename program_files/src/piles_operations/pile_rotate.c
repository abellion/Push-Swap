/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 20:10:01 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 17:47:18 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	pile_rotate(t_list **lst)
{
	t_list		*first;
	t_list		*last_prev;

	first = *lst;
	last_prev = lst_move_to(*lst, lst_count(*lst) - 1);
	*lst = last_prev->next;
	(*lst)->next = first;
	last_prev->next = NULL;
}
