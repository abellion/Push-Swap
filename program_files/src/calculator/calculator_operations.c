/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:51:18 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:51:21 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

int		operation_mode(t_piles *piles, int smaller, int nbr, int *mode)
{
	int				lst_len;
	int				position;
	static int		rotation;

	if (*mode == 1 && nbr == 0)
	{
		*mode = 2;
		lst_len = lst_count(piles->a);
		position = lst_search(piles->a, smaller);
		rotation = ((lst_len - position) > (lst_len / 2)) ? 3 : 4;
		nbr = rotation;
	}
	else if (*mode == 2 && nbr == 1)
		*mode = 1;
	else if (*mode == 2)
		nbr = rotation;
	return (nbr);
}

int		operation_determine(t_piles *piles, int smaller, int *mode)
{
	int				number;
	t_values		*values;

	values = values_init();
	values = values_put(piles->a, values);
	number = 0;
	if (values->last > values->last_prev)
		number = 2;
	else if (values->first < values->last)
		number = 3;
	else if (values->last > values->first)
		number = 4;
	if (number == 0 && (values->last == smaller))
		number = 1;
	values_delete(&values);
	return (operation_mode(piles, smaller, number, mode));
}

char	*operation_make(t_list **lst1, t_list **lst2, int number)
{
	if (number == 1)
		return (pile_push(lst2, lst1), "p");
	else if (number == 2)
		return (pile_swap(lst1), "s");
	else if (number == 3)
		return (pile_rev_rotate(lst1), "rr");
	else if (number == 4)
		return (pile_rotate(lst1), "r");
	return (0);
}

char	*operation_controller(t_piles *piles, int smaller, char pile)
{
	char			*operation;
	int				number;
	static int		mode;

	mode = (!mode) ? 1 : mode;
	operation = NULL;
	if (pile == 'b')
		operation = operation_make(&piles->b, &piles->a, 1);
	else if (pile == 'a')
	{
		number = operation_determine(piles, smaller, &mode);
		operation = operation_make(&piles->a, &piles->b, number);
	}
	if (!ft_strcmp(operation, "p"))
		pile = (pile == 'a') ? 'b' : 'a';
	operation = ft_strcjoin(operation, "", pile);
	return (operation);
}
