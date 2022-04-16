/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:07:18 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:10:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "list.h"

typedef struct s_stacks
{
	t_int_list	**stack_a;
	t_int_list	**stack_b;
	int			node_count;
}	t_stacks;

#endif
