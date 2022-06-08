/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:11:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 00:12:32 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	algorithm_handler(t_stack_pair *stacks, int node_count)
{
	int	min;
	int	max;

	if (node_count <= 0)
		return (EXIT_FAILURE);
	if (is_ordered(*stacks->stack_a) == 1)
		return (EXIT_SUCCESS);
	if (node_count <= 10)
		sort_low(stacks, node_count);
	//
	if (is_ordered(*(stacks->stack_a)) && stacks->stack_b != NULL)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
