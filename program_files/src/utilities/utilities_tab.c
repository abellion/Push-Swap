/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:53:43 by abellion          #+#    #+#             */
/*   Updated: 2015/02/18 18:14:16 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

int		tab_len(char **tab)
{
	int		index;

	index = 0;
	while (tab && tab[index])
		index++;
	return (index);
}

char	**tab_dup(char **tab)
{
	int		len;
	int		index;
	char	**new_tab;

	len = tab_len(tab);
	if (!(new_tab = (char **)malloc(sizeof(char **) * (len + 1))))
		return (0);
	index = 0;
	while (tab && tab[index])
	{
		new_tab[index] = ft_strdup(tab[index]);
		index++;
	}
	new_tab[index] = NULL;
	return (new_tab);
}

char	*tab_to_str(char **tab)
{
	int		index;
	char	*str;

	str = NULL;
	index = 0;
	while (tab && tab[index])
	{
		str = (!str) ? ft_strdup("") : str;
		str = ft_strjoin(str, tab[index]);
		index++;
	}
	return (str);
}
