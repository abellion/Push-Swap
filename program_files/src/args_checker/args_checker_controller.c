/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:20:39 by abellion          #+#    #+#             */
/*   Updated: 2015/03/05 18:15:04 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_pushswap.h"

int		input_check_number(char **input)
{
	int		index;

	index = 0;
	while (input && input[index])
	{
		if (!is_number(input[index]) || !is_integer(input[index]))
			return (0);
		index++;
	}
	return (1);
}

char	*str_clear_nbr(char *str)
{
	if (!str || (str && (!str[0] || !str[1])))
		return (str);
	str = (str[0] == '+') ? &str[1] : str;
	return (str);
}

int		input_check_duplicate(char **input)
{
	int		index;
	int		index_tmp;

	index = 0;
	input[index] = str_clear_nbr(input[index]);
	while (input[index])
	{
		index_tmp = index + 1;
		while (input[index_tmp])
		{
			input[index_tmp] = str_clear_nbr(input[index_tmp]);
			if (!ft_strcmp(input[index], input[index_tmp]))
				return (0);
			index_tmp++;
		}
		index++;
	}
	return (1);
}

void	input_checker_controller(char **input)
{
	if (!(tab_len(input)))
		ft_error();
	if (!input_check_number(input))
		ft_error();
	if (!input_check_duplicate(input))
		ft_error();
}
