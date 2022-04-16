/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:55:10 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 21:31:16 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	delete_node(t_int_list *node, void (*del)(int))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}

void	list_clear(t_int_list **lst, void (*del)(int))
{
	t_int_list	*acc;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		acc = (*lst)->next;
		delete_node(*lst, del);
		*lst = acc;
	}
	*lst = NULL;
}
