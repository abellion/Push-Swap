/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:37:19 by abellion          #+#    #+#             */
/*   Updated: 2015/02/24 15:57:52 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

int		is_options(char *str)
{
	if (str && str[0] && str[0] == '-')
		return (1);
	return (0);
}

int		is_valid_options(char *curent_options, char *available_options)
{
	int		index;

	index = 1;
	while (curent_options && curent_options[index])
	{
		if (!ft_strchr(available_options, curent_options[index]))
			return (0);
		index++;
	}
	return ((is_options(curent_options) ? 1 : 0));
}

char	*options_formater(char **args, char *available_options)
{
	int		i;
	char	*formated;

	formated = NULL;
	i = 0;
	while (args && args[i] && is_valid_options(args[i], available_options))
	{
		formated = (!formated) ? ft_strdup("") : formated;
		formated = ft_strjoin(formated, &args[i][1]);
		i++;
	}
	return (formated);
}

char	**input_formater(char **args, char *options)
{
	int		index;

	index = 0;
	while (args && args[index])
	{
		if (!is_options(args[index]) || (is_options(args[index]) &&
					!ft_strstr(options, &args[index][1])))
			return (tab_dup(&args[index]));
		index++;
	}
	return (0);
}
