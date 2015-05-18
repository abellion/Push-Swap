/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_lst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:55:13 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:55:15 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

t_list		*lst_to_int(t_list *lst)
{
	t_list		*begin;
	int			*nb;

	begin = lst;
	while (lst)
	{
		if (!(nb = (int *)malloc(sizeof(int))))
			return (0);
		*nb = ft_atoi(lst->content);
		lst->content = nb;
		lst->content_size = 0;
		lst = lst->next;
	}
	return (begin);
}

int			lst_is_sort(t_list *lst, int order)
{
	int		curent;
	int		next;

	while (lst && lst->next)
	{
		curent = *((int *)lst->content);
		next = *((int *)lst->next->content);
		if (order == 1 && curent > next)
			return (0);
		else if (order == 2 && curent < next)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int			lst_search(t_list *lst, int nb)
{
	int		curent_nb;
	int		index;

	index = 1;
	while (lst)
	{
		curent_nb = *((int *)lst->content);
		if (curent_nb == nb)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}
