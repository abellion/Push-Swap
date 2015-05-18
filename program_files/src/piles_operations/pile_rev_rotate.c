/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 20:20:23 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 17:54:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void		pile_rev_rotate(t_list **lst)
{
	t_list		*first;
	t_list		*last;

	first = *lst;
	last = lst_move_to(*lst, lst_count(*lst));
	*lst = first->next;
	last->next = first;
	last->next->next = NULL;
}
