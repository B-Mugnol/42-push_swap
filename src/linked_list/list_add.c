/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:29:58 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/14 21:10:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_int_list	*new_node(int content)
{
	t_int_list	*lst;

	lst = malloc(sizeof(t_int_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	append_node_to_list(t_int_list **lst, t_int_list *new)
{
	t_int_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = get_last_node(*lst);
		last->next = new;
	}
}

void	append_list_to_node(t_int_list **lst, t_int_list *new)
{
	t_int_list	*last_new;

	if (!new)
		return ;
	if (!lst)
		*lst = new;
	else
	{
		last_new = get_last_node(new);
		last_new->next = *lst;
		*lst = new;
	}
}
