/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:18 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 19:17:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

#include "list.h"
#include "ft_printf.h"

// swap.c
void	swap_a(t_int_list **stack_a);
void	swap_b(t_int_list **stack_b);
void	swap_both(t_int_list **stack_a, t_int_list **stack_b);

#endif
