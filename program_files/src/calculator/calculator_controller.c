/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:47:31 by abellion          #+#    #+#             */
/*   Updated: 2015/03/05 18:20:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

char		*calculator_make(t_piles *piles, int is_sort)
{
	int				smaller;
	char			*operation;
	t_list			*tmp;
	static t_list	*lst_sorted;

	operation = NULL;
	lst_sorted = (!lst_sorted) ? merge_sort(lst_dup(piles->a)) : lst_sorted;
	smaller = *((int *)(lst_sorted)->content);
	if (!is_sort)
		operation = operation_controller(piles, smaller, 'a');
	else
		operation = operation_controller(piles, smaller, 'b');
	if (operation && !ft_strcmp(operation, "pb"))
	{
		tmp = lst_sorted;
		ft_lstdelone(&tmp, del);
		lst_sorted = (lst_sorted)->next;
	}
	return (operation);
}

int			calculator_operator(t_piles *piles, t_list **operations)
{
	int				is_sort;
	char			*operation;
	static t_list	*begin;

	begin = (!begin) ? *operations : begin;
	is_sort = lst_is_sort(piles->a, 2);
	if (!is_sort || lst_count(piles->b))
	{
		operation = calculator_make(piles, is_sort);
		(*operations)->next = ft_lstnew(operation, ft_strlen(operation));
		*operations = (*operations)->next;
		ft_strdel(&operation);
		return (1);
	}
	*operations = begin->next;
	return (0);
}

t_list		*calculator_controller(char **input, char *options)
{
	t_piles			*piles;
	t_list			*operations;

	piles = piles_init();
	piles->a = lst_to_int(lst_rev(tab_to_lst(input)));
	operations = ft_lstnew(NULL, 0);
	while (calculator_operator(piles, &operations))
	{
		if (ft_strchr(options, 'd'))
			printer_details(piles, operations->content, options);
	}
	piles_delete(&piles);
	return (operations);
}
