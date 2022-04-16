/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:44:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:14:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	swap_first_nodes(t_int_list **lst);

void	swap_a(t_stacks *stacks)
{
	swap_first_nodes(stacks->stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stacks *stacks)
{
	swap_first_nodes(stacks->stack_b);
	ft_printf("sb\n");
}

void	swap_both(t_stacks *stacks)
{
	swap_first_nodes(stacks->stack_a);
	swap_first_nodes(stacks->stack_b);
	ft_printf("ss\n");
}

static void	swap_first_nodes(t_int_list **lst)
{
	t_int_list	*new_start;
	t_int_list	*acc;

	if (!*lst || !(*lst)->next)
		return ;
	new_start = (*lst)->next;
	acc = new_start->next;
	new_start->next = *lst;
	(*lst)->next = acc;
	*lst = new_start;
}
