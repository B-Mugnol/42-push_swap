/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:45:09 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 20:44:50 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	is_ordered(t_int_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min(t_int_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->content < min)
			min = stack->content;
	}
	return (min);
}

int	get_distance(t_int_list *stack, int value)
{
	int	distance;

	distance = 0;
	while (stack)
	{
		if (stack->content == value)
			return (distance);
		distance++;
		stack = stack->next;
	}
	return (-1);
}

int	compare_nodes_1_2(t_int_list *stack)
{
	if (!stack)
		return (0);
	if (stack->content > stack->next->content)
		return (1);
	return (-1);
}

int	compare_nodes_1_3(t_int_list *stack)
{
	if (!stack)
		return (0);
	if (stack->content > stack->next->next->content)
		return (1);
	return (-1);
}
