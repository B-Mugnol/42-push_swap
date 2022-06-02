/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:11:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/02 20:36:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	is_ordered(t_int_list *stack);

int	algorithm_handler(t_stack_pair *stacks, int node_count)
{
	if (node_count <= 0)
		return (EXIT_FAILURE);
	if (is_ordered(*(stacks->stack_a)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	is_ordered(t_int_list *stack)
{
	if (!stack)
		return (EXIT_SUCCESS);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (EXIT_FAILURE);
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}
