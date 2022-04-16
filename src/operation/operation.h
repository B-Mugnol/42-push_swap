/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:18 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:27:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "list.h"		// t_int_list and its related functions
# include "struct.h"	// t_stack_pair declaration
# include "ft_printf.h"

// swap.c
void	swap_a(t_stack_pair *stacks);
void	swap_b(t_stack_pair *stacks);
void	swap_both(t_stack_pair *stacks);

// push.c
void	push_to_a(t_stack_pair *stacks);
void	push_to_b(t_stack_pair *stacks);

#endif
