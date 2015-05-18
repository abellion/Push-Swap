/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 18:31:17 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:58:21 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

t_list		*tab_to_lst(char **tab)
{
	int			index;
	t_list		*lst;
	t_list		*begin;

	index = 0;
	lst = ft_lstnew(NULL, 0);
	begin = lst;
	while (tab && tab[index])
	{
		lst->next = ft_lstnew(tab[index], ft_strlen(tab[index]));
		lst = lst->next;
		index++;
	}
	lst = begin->next;
	ft_lstdelone(&begin, del);
	return (lst);
}

t_list		*lst_move_to(t_list *lst, int nb)
{
	int			index;

	index = 1;
	while (lst && index < nb)
	{
		index++;
		lst = lst->next;
	}
	return (lst);
}

t_list		*lst_rev(t_list *lst)
{
	t_list		*prev;
	t_list		*next;

	prev = NULL;
	while (lst)
	{
		next = lst->next;
		if (!prev)
			lst->next = NULL;
		else
			lst->next = prev;
		prev = lst;
		lst = next;
	}
	return (prev);
}

t_list		*lst_dup(t_list *lst)
{
	t_list		*new_lst;
	t_list		*begin;

	new_lst = ft_lstnew(NULL, 0);
	begin = new_lst;
	while (lst)
	{
		new_lst->next = ft_lstnew(lst->content, ft_strlen(lst->content));
		lst = lst->next;
		new_lst = new_lst->next;
	}
	new_lst = begin->next;
	ft_lstdelone(&begin, del);
	return ((!new_lst) ? NULL : new_lst);
}

int			lst_count(t_list *lst)
{
	int			index;

	index = 0;
	while (lst)
	{
		index++;
		lst = lst->next;
	}
	return (index);
}
