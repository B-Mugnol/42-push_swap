/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:07:18 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/04/16 20:27:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "list.h"

typedef struct s_stack_pair
{
	t_int_list	**stack_a;
	t_int_list	**stack_b;
	int			node_count;
}	t_stack_pair;

#endif
