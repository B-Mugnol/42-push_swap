/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:26:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 21:56:42 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

// Int linked list struct:
typedef struct s_int_list
{
	int					content;
	struct s_int_list	*next;
}	t_int_list;

// list_add.c
t_int_list	*new_node(int content);
void		append_list_to_node(t_int_list **lst, t_int_list *new);
void		append_node_to_list(t_int_list **lst, t_int_list *new);

// list_get.c
t_int_list	*find(t_int_list *lst, int (*compare_fn)(int, int), int test_param);
t_int_list	*get_second_to_last_node(t_int_list *lst);
t_int_list	*get_last_node(t_int_list *lst);
int			get_list_size(t_int_list *lst);

// list_remove.c
void		delete_node(t_int_list *node, void (*del)(int));
void		list_clear(t_int_list **lst, void (*del)(int));

#endif
