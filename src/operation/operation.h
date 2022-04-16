/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:18 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:18:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "list.h"		// t_int_list and its related functions
# include "struct.h"	// t_stacks declaration
# include "ft_printf.h"

// swap.c
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);

// push.c
void	push(t_int_list **src, t_int_list **dest);

#endif
