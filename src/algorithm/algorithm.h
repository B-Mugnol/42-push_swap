/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:00:56 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 00:12:06 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "struct.h"
# include "operation.h"

// algorithm.c
int	algorithm_handler(t_stack_pair *stacks, int node_count);

// aux.c
int	is_ordered(t_int_list *stack);
int	get_min(t_int_list *stack);
int	get_distance(t_int_list *stack, int value);
int	compare_nodes_1_2(t_int_list *stack);
int	compare_nodes_1_3(t_int_list *stack);

// sort_low.c
void	sort_low(t_stack_pair *stacks, int node_count);

#endif
