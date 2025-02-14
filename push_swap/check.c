/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:11:40 by bozil             #+#    #+#             */
/*   Updated: 2025/01/29 10:11:40 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

static void print_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

static long ft_atol(const char *str)
{
    long num = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '+' || *str == '-')
        if (*str++ == '-')
            sign = -1;
    if (*str < '0' || *str > '9')
        print_error();
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
            print_error();
        str++;
    }
    if (*str != '\0')
        print_error();
    return (num * sign);
}

static int is_duplicate(t_node *head, int num)
{
    while (head)
    {
        if (head->value == num)
            return (1);
        head = head->next;
    }
    return (0);
}

t_node *parse_args(char **argv)
{
    t_node *stack = NULL;
    t_node *new;
    int num;
    
    while (*argv)
    {
        num = ft_atol(*argv);
        if (is_duplicate(stack, num))
            print_error();
        new = malloc(sizeof(t_node));
        if (!new)
            exit(1);
        new->value = num;
        new->next = stack;
        stack = new;
        argv++;
    }
    return (stack);
}