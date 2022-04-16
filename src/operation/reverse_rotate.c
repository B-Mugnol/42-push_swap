/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:44:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 22:05:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void	reverse_rotate(t_int_list **lst);

void	reverse_rotate_a(t_stack_pair *stacks)
{
	reverse_rotate(stacks->stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack_pair *stacks)
{
	reverse_rotate(stacks->stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_all(t_stack_pair *stacks)
{
	reverse_rotate(stacks->stack_a);
	reverse_rotate(stacks->stack_b);
	ft_printf("rrr\n");
}

static void	reverse_rotate(t_int_list **lst)
{
	t_int_list *second_to_last;
	t_int_list *last;

	if (!lst || !*lst)
		return ;
	second_to_last = get_second_to_last_node(*lst);
	if (!second_to_last->next)
		return ;
	last = second_to_last->next;
	second_to_last->next = NULL;
	append_list_to_node(lst, last);
}
