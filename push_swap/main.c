/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:17 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 11:31:17 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_node *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./push_swap [numbers]\n");
        return (1);
    }

    t_node *stack_a = parse_args(argv + 1);
    t_node *stack_b = NULL;

    printf("Avant tri:\n");
    print_stack(stack_a, "Stack A");

    sort_stack(&stack_a, &stack_b);

    printf("Après tri:\n");
    print_stack(stack_a, "Stack A");

    return (0);
}
