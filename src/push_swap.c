/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/09 05:04:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_list	*to_linked_list(int argc, char **argv);
static int	is_digit_str(const char *str);
static int	is_equal(int a, int b);

int	main(int argc, char **argv)
{
	t_int_list		*stack_a;
	t_int_list		*stack_b;
	t_stack_pair	stacks;
	int				exit_status;

	if (argc == 1)
		return (EXIT_SUCCESS);
	stack_a = to_linked_list(argc, argv);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	stacks = (t_stack_pair){.stack_a = &stack_a, .stack_b = &stack_b};
	exit_status = algorithm_handler(&stacks, argc - 1);
	list_clear(stacks.stack_a, NULL);
	list_clear(stacks.stack_b, NULL);
	return (exit_status);
}

t_int_list	*to_linked_list(int argc, char **argv)
{
	t_int_list	*prev_node;
	t_int_list	*curr_node;
	int			value;

	curr_node = NULL;
	while (--argc > 0)
	{
		value = ft_atoi(argv[argc]);
		if (!is_digit_str(argv[argc]) || value != ft_atoll(argv[argc]))
		{
			list_clear(&curr_node, NULL);
			break ;
		}
		prev_node = new_node(value);
		if (find(curr_node, is_equal, prev_node->content))
		{
			delete_node(prev_node, NULL);
			list_clear(&curr_node, NULL);
			break ;
		}
		append_list_to_node(&curr_node, prev_node);
		curr_node = prev_node;
	}
	return (curr_node);
}

static int	is_equal(int a, int b)
{
	return (a == b);
}

static int	is_digit_str(const char *str)
{
	if (!str || !*str || (*str != '-' && !ft_isdigit(*str)))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
