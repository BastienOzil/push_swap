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

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

t_node	*parse_args(char **argv, char **split_argv);
t_node	*create_new_node(int num, t_node **stack, char **split_argv);

void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

void	push(t_node **src, t_node **dst);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

int		stack_size(t_node *stack);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_large(t_node **stack_a, t_node **stack_b);

void	move_to_top(t_node **stack, int index);
int		find_min_index(t_node *stack);
int		is_sorted(t_node *stack);

char	**ft_split(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

long	ft_atol(const char *str, char **split_argv);
long	convert_to_long(const char **str, char **split_argv);
int		get_sign(const char **str);
int		is_valid_input(char *arg);
int		is_duplicate(t_node *head, int num);
int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
char	**split_args(char *arg);

void	free_stack(t_node **stack);
void	print_stack(t_node *stack, char *name);
void	free_split(char **split);
void	print_error(void);
void	print_error_and_free(t_node **stack, char **split_argv);
void	sort_stack(t_node **stack_a, t_node **stack_b);
int		stack_get_at_index(t_node *stack, int index);
int		are_valid_args(char **args);

t_node	*handle_single_arg(char *arg);
t_node	*handle_multiple_args(char **args);
void	start_sorting(t_node **stack_a, t_node **stack_b);
void	shift_stack(t_node *stack);

#endif
