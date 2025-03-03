/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:21:42 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 10:21:42 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void print_stack(t_node *stack, char *name)
{
    ft_printf("%s: ", name);
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("Usage: ./push_swap [numbers]\n");
        return (1);
    }

    t_node *stack_a = parse_args(argv + 1);
    t_node *stack_b = NULL;

    sort_stack(&stack_a, &stack_b);

    return (0);
}
