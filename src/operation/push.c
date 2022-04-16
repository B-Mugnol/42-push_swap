/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:30:37 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:27:16 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	push(t_int_list **src, t_int_list **dest);

void	push_to_a(t_stack_pair *stacks)
{
	push(stacks->stack_b, stacks->stack_a);
	ft_printf("pa\n");
}

void	push_to_b(t_stack_pair *stacks)
{
	push(stacks->stack_a, stacks->stack_b);
	ft_printf("pb\n");
}

static void	push(t_int_list **src, t_int_list **dest)
{
	t_int_list	*acc;

	if (!*src)
		return ;
	acc = *src;
	*src = (*src)->next;
	acc->next = NULL;
	append_list_to_node(dest, acc);
}
