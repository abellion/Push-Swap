/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 19:08:44 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 14:58:31 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

void	pile_push(t_list **to, t_list **from)
{
	t_list		*elem_from;
	t_list		*prev_elem_from;
	int			lstlen_from;
	int			lstlen_to;

	lstlen_from = lst_count(*from);
	lstlen_to = lst_count(*to);
	prev_elem_from = lst_move_to(*from, lstlen_from - 1);
	elem_from = (lstlen_from - 1) ? prev_elem_from->next : prev_elem_from;
	if (lstlen_to)
		lst_move_to(*to, lstlen_to)->next = elem_from;
	else
		*to = elem_from;
	if (lstlen_from - 1)
		prev_elem_from->next = NULL;
	else
		*from = NULL;
}
