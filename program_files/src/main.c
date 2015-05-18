/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:27:36 by abellion          #+#    #+#             */
/*   Updated: 2015/02/25 15:19:07 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pushswap.h"

void		ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	char		*options_formated;
	char		**input_formated;
	t_list		*operations;

	options_formated = options_formater(&av[1], "vdi");
	input_formated = input_formater(&av[1], options_formated);
	input_checker_controller(input_formated);
	operations = calculator_controller(input_formated, options_formated);
	printer_controller(operations, options_formated);
	ft_lstdel(&operations, del);
	ft_strdel(&options_formated);
	ac = ac;
	return (0);
}
