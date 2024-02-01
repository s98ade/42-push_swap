/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:22:40 by sade              #+#    #+#             */
/*   Updated: 2024/02/01 10:14:38 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/*check*/
void	arg_check(char **argv);
int		is_sorted(t_stack **stack);
int		ft_isnbr(char *nbr);
int		is_dup(int num, char **args, int i);
int		error_syntax(char *str_nbr);

/*check_utils*/
int		arg_is_zero(char *av);
int		is_sign(char c);

/*utils*/
void	ft_putstr(char *str);
void	free_stack(t_stack **stack);
void	ft_free(char **argv);
void	error(char *msg);

/*stack_utils*/
t_stack	*stack_new(int value);
int		stack_size(t_stack *stack);
t_stack	*get_stack_last(t_stack *stack);
int		add_stack_last(t_stack **stack, t_stack *new);
t_stack	*get_before_last(t_stack *stack);

/*initialization*/
t_stack	*make_new(int nbr);
t_stack	*append_stack(t_stack *stack_a, int nbr);
t_stack	*fill_stack_one(int argc, char **argv);
t_stack	*fill_stack(int argc, char **argv);
void	assign_idx(t_stack *stack_a, int size);

/*main*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
t_stack	*fill_split(int argc, char **argv);
int		main(int argc, char **argv);

/*mini_sort*/
int		get_distance(t_stack **stack, int index);
int		find_smallest(t_stack **stack, int val);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

/*micro_sort*/
int		find_biggest(t_stack *stack);
void	sort_3(t_stack **stack);

/*sort*/
int		get_max_bits(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);

/*swap*/
void	swap(t_stack *stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

/*rotate*/
void	rotate(t_stack **stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

/*push*/
void	push(t_stack **stack_to, t_stack **stack_from);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_b, t_stack **stack_a);

/*reverse rotate*/
void	rev_rotate(t_stack **stack);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif