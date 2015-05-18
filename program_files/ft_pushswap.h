/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:29:42 by abellion          #+#    #+#             */
/*   Updated: 2015/02/25 15:17:32 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

/*
** Declaration de structures
*/
typedef struct	s_piles
{
	t_list		*a;
	t_list		*b;
}				t_piles;

typedef struct	s_values
{
	int			first;
	int			last;
	int			last_prev;
}				t_values;

/*
** Prototypes main
*/
void			ft_error(void);

/*
** Prototypes utilities args
*/
int				is_options(char *str);
int				is_valid_options(char *curent_options, char *available_options);
char			*options_formater(char **args, char *available_options);
char			**input_formater(char **args, char *options);

/*
** Prototypes utilities type
*/
int				is_number(char *str);
int				is_integer(char *str);

/*
** Prototypes utilities tab
*/
int				tab_len(char **tab);
char			**tab_dup(char **tab);
char			*tab_to_str(char **tab);

/*
** Prototypes utilities lst
*/
t_list			*tab_to_lst(char **tab);
t_list			*lst_rev(t_list *lst);
t_list			*lst_move_to(t_list *lst, int nb);
t_list			*lst_to_int(t_list *lst);
t_list			*lst_dup(t_list *lst);
int				lst_count(t_list *lst);
int				lst_is_sort(t_list *lst, int order);
int				lst_search(t_list *lst, int nb);

/*
** Prototypes utilities sort
*/
t_list			*merge(t_list *part1, t_list *part2);
t_list			*separe_lst(t_list *lst);
t_list			*insert(t_list *elem, t_list *sequence);
t_list			*merge_sort(t_list *sequence);

/*
** Prototypes args checker
*/
void			input_checker_controller(char **input);
int				input_check_number(char **input);
int				input_check_duplicate(char **input);
char			*str_clear_nbr(char *str);

/*
** Prototypes piles operations
*/
void			pile_swap(t_list **lst);
void			pile_push(t_list **to, t_list **from);
void			pile_rotate(t_list **lst);
void			pile_rev_rotate(t_list **lst);

/*
** Prototypes calculator
*/
t_piles			*piles_init(void);
void			piles_delete(t_piles **piles);
t_values		*values_init(void);
void			values_delete(t_values **values);
t_values		*values_put(t_list *lst, t_values *values);
t_list			*calculator_controller(char **input, char *options);
char			*calculator_make(t_piles *piles, int is_sort);
int				calculator_operator(t_piles *piles, t_list **operations);
char			*operation_controller(t_piles *piles, int smaller, char pile);
int				operation_determine(t_piles *piles, int smaller, int *mode);
int				operation_mode(t_piles *piles, int smaller, int nbr, int *mode);
char			*operation_make(t_list **lst1, t_list **lst2, int number);

/*
** Prototypes printer
*/
void			printer_controller(t_list *operations, char *options);
void			printer_lst_str(t_list *lst);
void			printer_lst_nbr(t_list *lst);
void			printer_operations(t_list *operations, char *options);
void			printer_details(t_piles *piles, char *operation, char *options);
void			printer_infos(t_list *operations, char *options);

#endif
