/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:15:08 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 10:15:08 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_node **src, t_node **dst)
{
    t_node *temp;

    if (!src || !*src)
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}

void pa(t_node **stack_a, t_node **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}