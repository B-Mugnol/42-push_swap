/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:13:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 22:07:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	rotate(t_int_list **lst);

void	rotate_a(t_stack_pair *stacks)
{
	rotate(stacks->stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack_pair *stacks)
{
	rotate(stacks->stack_b);
	ft_printf("rb\n");
}

void	rotate_all(t_stack_pair *stacks)
{
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
	ft_printf("rr\n");
}

static void	rotate(t_int_list **lst)
{
	t_int_list	*acc;

	if (!lst || !*lst)
		return ;
	acc = *lst;
	*lst = (*lst)->next;
	acc->next = NULL;
	append_node_to_list(lst, acc);
}
