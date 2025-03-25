/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:42:47 by bozil             #+#    #+#             */
/*   Updated: 2025/03/17 13:42:47 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../utils/libft/libft.h"

char	**split_args(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		print_error();
	if (!args[0])
	{
		free(args);
		print_error();
	}
	return (args);
}


void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_stack(t_node *stack, char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void    free_stack(t_node **stack)
{
    t_node   *head;
    t_node   *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split_argv;

	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap numbers\n");
		return (1);
	}
	if (argc == 2)
	{
		split_argv = split_args(argv[1]);
		stack_a = parse_args(split_argv);
		free_split(split_argv);
	}
	else
		stack_a = parse_args(argv + 1);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
