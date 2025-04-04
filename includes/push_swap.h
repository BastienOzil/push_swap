/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:41:38 by bozil             #+#    #+#             */
/*   Updated: 2025/03/27 14:41:38 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

int     is_number(char *str);
int     are_valid_args(char **args);

int     is_duplicate(t_node *head, int num);
int     get_sign(const char **str);
int     is_valid_input(char *arg);
long    ft_atol(const char *str, char **split_argv);
long    convert_to_long(const char **str, char **split_argv);
void    check_end_of_number(const char **str, char **split_argv);

t_node  *create_new_node(int num, t_node **stack, char **split_argv);
void    print_error(void);
void    print_error_and_free(t_node **stack, char **split_argv);
void    free_stack(t_node **stack);
void    print_stack(t_node *stack, char *name);

t_node  *handle_single_arg(char *arg);
t_node  *handle_multiple_args(char **args);
void    start_sorting(t_node **stack_a, t_node **stack_b);

t_node  *parse_args(char **argv, char **split_argv);
char    **split_args(char *arg);
void    free_split(char **split);

void    push(t_node **src, t_node **dst);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);

int     find_min(t_node *stack);
int     stack_contains_large_positive(t_node *stack);
void    shift_stack(t_node *stack);

void    reverse_rotate(t_node **stack);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);

void    rotate(t_node **stack);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);

void    move_stack_b(t_node **stack_a, t_node **stack_b, int bit);
void    normalize(t_node *stack);
void    sort_large(t_node **stack_a, t_node **stack_b);

void    sort_stack(t_node **stack_a, t_node **stack_b);
void    sort_two(t_node **stack_a);
void    sort_three(t_node **stack_a);
void    sort_four(t_node **stack_a, t_node **stack_b);
void    sort_five(t_node **stack_a, t_node **stack_b);

int     is_sorted(t_node *stack);
void    swap(t_node **stack);
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);

int     stack_size(t_node *stack);
int     find_min_index(t_node *stack);
int     stack_get_at_index(t_node *stack, int index);
void    move_to_top(t_node **stack, int index);

/* Nouvelles fonctions pour optimisations */
int     count_pushable_bits(t_node *stack, int bit, int size);
int     partition(int *arr, int low, int high);
int     calc_max_bits(int size);
int     should_use_insertion(int size);
void    quick_sort_recursive(int *arr, int low, int high);
void    sort_array(int *arr, int size);
void    fill_sorted_array(t_node *stack, int *arr);
void    rank_values(t_node *stack, int *sorted, int size);
void    optimize_normalize(t_node *stack);
void    push_min_elements(t_node **stack_a, t_node **stack_b, int count);
void    push_back_all(t_node **stack_a, t_node **stack_b, int count);
void    sort_small_insertion(t_node **stack_a, t_node **stack_b, int size);
void    optimize_push_to_b(t_node **stack_a, t_node **stack_b, int bit);
void    swap_ints(int *a, int *b);

#endif
