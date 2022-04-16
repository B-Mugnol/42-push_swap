/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:08:24 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 21:56:05 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_int_list	*find(t_int_list *lst, int (*compare_fn)(int, int), int test_param)
{
	if (!lst)
		return (lst);
	while (lst)
	{
		if (compare_fn(lst->content, test_param))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_int_list	*get_second_to_last_node(t_int_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_int_list	*get_last_node(t_int_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	get_list_size(t_int_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
