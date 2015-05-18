/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:55:26 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:55:28 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

t_list		*merge(t_list *part1, t_list *part2)
{
	t_list	*elem;
	t_list	*next;

	if (!part1)
		return (part2);
	else if (!part2)
		return (part1);
	elem = ft_lstnew(part1->content, ft_strlen(part1->content));
	next = part1->next;
	ft_lstdelone(&part1, &del);
	return (merge(next, insert(elem, part2)));
}

t_list		*separe_lst(t_list *lst)
{
	t_list *prev;
	t_list *slow;

	slow = lst;
	prev = NULL;
	while (lst && lst->next)
	{
		lst = lst->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (prev)
		prev->next = NULL;
	return (slow);
}

t_list		*insert(t_list *elem, t_list *sequence)
{
	int		nbr_elem;
	int		nbr_sequence;

	nbr_elem = *((int *)elem->content);
	nbr_sequence = *((int *)sequence->content);
	if (nbr_elem <= nbr_sequence)
		return (elem->next = sequence, elem);
	if (!sequence->next)
	{
		if (nbr_elem > nbr_sequence)
			return (sequence->next = elem, sequence);
		else
			return (elem);
	}
	else
		sequence->next = insert(elem, sequence->next);
	return (sequence);
}

t_list		*merge_sort(t_list *sequence)
{
	t_list		*part1;
	t_list		*part2;

	if (!sequence || !sequence->next)
		return (sequence);
	part1 = sequence;
	part2 = separe_lst(sequence);
	return (merge(merge_sort(part1), merge_sort(part2)));
}
