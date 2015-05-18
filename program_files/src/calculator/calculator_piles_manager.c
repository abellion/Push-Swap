/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_piles_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:40:34 by abellion          #+#    #+#             */
/*   Updated: 2015/04/04 20:02:49 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

t_piles		*piles_init(void)
{
	t_piles		*piles;

	if (!(piles = (t_piles *)malloc(sizeof(t_piles))))
		return (0);
	piles->a = NULL;
	piles->b = NULL;
	return (piles);
}

void		piles_delete(t_piles **piles)
{
	if (piles && *piles)
	{
		ft_lstdel(&(*piles)->a, del);
		ft_lstdel(&(*piles)->b, del);
		free(*piles);
		*piles = NULL;
	}
}
