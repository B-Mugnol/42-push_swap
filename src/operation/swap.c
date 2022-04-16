/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:44:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 19:17:20 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	swap_first_nodes(t_int_list **lst);

void	swap_a(t_int_list **stack_a)
{
	swap_first_nodes(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_int_list **stack_b)
{
	swap_first_nodes(stack_b);
	ft_printf("sb\n");
}

void	swap_both(t_int_list **stack_a, t_int_list **stack_b)
{
	swap_first_nodes(stack_a);
	swap_first_nodes(stack_b);
	ft_printf("ss\n");
}

static void	swap_first_nodes(t_int_list **lst)
{
	t_int_list	*new_start;
	t_int_list	*acc;

	new_start = (*lst)->next;
	acc = new_start->next;
	new_start->next = *lst;
	(*lst)->next = acc;
	*lst = new_start;
}
