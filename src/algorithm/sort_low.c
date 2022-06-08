/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:43:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 00:09:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void	sort_3(t_stack_pair *stacks);

void	sort_low(t_stack_pair *stacks, int node_count)
{
	int	distance;

	if (is_ordered(*stacks->stack_a) == 1)
		return ;
	if (node_count == 2)
		swap_a(stacks);
	else if (node_count == 3)
		sort_3(stacks);
	distance = get_distance(*stacks->stack_a, get_min(*stacks->stack_a));
	if (distance <= node_count / 2)
		while (distance--)
			rotate_a(stacks);
	else
		while (distance++ != node_count)
			reverse_rotate_a(stacks);
	if (is_ordered(*stacks->stack_a))
		return ;
	push_to_b(stacks);
	if (node_count == 3)
		sort_3(stacks);
	else
		sort_low(stacks, node_count - 1);
	push_to_a(stacks);
}

static void	sort_3(t_stack_pair *stacks)
{
	if (is_ordered(*stacks->stack_a) == 1)
		return ;
	if (compare_nodes_1_2(*stacks->stack_a) > 0
		&& compare_nodes_1_3(*stacks->stack_a) > 0)
	{
		rotate_a(stacks);
		if (compare_nodes_1_2(*stacks->stack_a) > 0)
			swap_a(stacks);
		return ;
	}
	if (compare_nodes_1_2(*stacks->stack_a) < 0)
	{
		reverse_rotate_a(stacks);
		if (compare_nodes_1_2(*stacks->stack_a) > 0)
			swap_a(stacks);
		return ;
	}
	if (compare_nodes_1_2(*stacks->stack_a) > 0
		&& compare_nodes_1_3(*stacks->stack_a) < 0)
	{
		swap_a(stacks);
		return ;
	}
}
