/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:22:53 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 02:06:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static size_t	get_index(int value, int min);

void	radix_sort(t_stack_pair *stacks, int node_count, int digit)
{
	int	i;
	int	min;

	if (is_ordered(*(stacks->stack_a)))
		return ;
	i = 0;
	min = get_min(*stacks->stack_a);
	while (i < node_count)
	{
		if (get_index((*stacks->stack_a)->content, min) & 1 << digit)
			rotate_a(stacks);
		else
			push_to_b(stacks);
		i++;
	}
	while (*stacks->stack_b)
		push_to_a(stacks);
	radix_sort(stacks, node_count, digit + 1);
}

static size_t	get_index(int value, int min)
{
	if (min < 0)
		return ((size_t)(value) - min);
	return ((size_t)(value) + min);
}
