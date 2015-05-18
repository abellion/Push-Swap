/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_values_manager.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:52:09 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:52:30 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

t_values	*values_init(void)
{
	t_values	*values;

	if (!(values = (t_values *)malloc(sizeof(t_values))))
		return (0);
	values->first = 0;
	values->last = 0;
	values->last_prev = 0;
	return (values);
}

void		values_delete(t_values **values)
{
	if (values && *values)
	{
		free(*values);
		*values = NULL;
	}
}

t_values	*values_put(t_list *lst, t_values *values)
{
	t_list		*last_prev;
	int			lstlen;

	if (!lst || !values)
		return (0);
	lstlen = lst_count(lst);
	last_prev = lst_move_to(lst, lstlen - 1);
	values->first = *((int *)lst->content);
	values->last_prev = *((int *)last_prev->content);
	if (lstlen >= 2)
		values->last = *((int *)last_prev->next->content);
	else
		values->last = *((int *)last_prev->content);
	return (values);
}
