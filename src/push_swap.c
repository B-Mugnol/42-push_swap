/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/06/02 20:39:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_int_list *lst);//
static void	print_stacks(t_stack_pair stacks);//
t_int_list	*to_linked_list(int argc, char **argv);
static int	is_digit_str(const char *str);
static int	is_equal(int a, int b);
# include <stdio.h>

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
	// printf("%i, %i\n", stacks.node_count, get_list_size(*stacks.stack_a));
	// print_stacks(stacks);
		// reverse_rotate_all(&stacks);
		// rotate_a(&stacks);
		// rotate_b(&stacks);
		// swap_both(&stacks);
		// push_to_a(&stacks);
		// push_to_b(&stacks);
	// print_stacks(stacks);
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

static void	print_list(t_int_list *lst)
{
	if (!lst)
	{
		printf("Empty list\n");
		return ;
	}
	while (lst)
	{
		printf("%i > ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

static void	print_stacks(t_stack_pair stacks)
{
	printf("a: ");
	if (!stacks.stack_a)
		print_list(NULL);
	else
		print_list(*stacks.stack_a);
	printf("b: ");
	if (!stacks.stack_b)
		print_list(NULL);
	else
		print_list(*stacks.stack_b);
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
