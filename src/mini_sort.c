/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:38:28 by sade              #+#    #+#             */
/*   Updated: 2024/01/28 15:48:04 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack **stack, int val)
{
	int		smallest;
	t_stack	*tmp;

	tmp = *stack;
	smallest = (tmp)->index;
	while ((tmp)->next)
	{
		tmp = (tmp)->next;
		if (((tmp)->index < smallest) && (tmp)->index != val)
			smallest = (tmp)->index;
	}
	return (smallest);
}

int	get_distance(t_stack **stack, int index)
{
	int		distance;
	t_stack	*tmp;

	tmp = *stack;
	distance = 0;
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, find_smallest(stack_a, -1));
	if (distance == 1)
		do_ra(stack_a);
	else if (distance == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (distance == 3)
		do_rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	do_pb(stack_a, stack_b);
	sort_3(stack_a);
	do_pa(stack_b, stack_a);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, find_smallest(stack_a, -1));
	if (distance == 1)
		do_ra(stack_a);
	else if (distance == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (distance == 3)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	else if (distance == 4)
		do_rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	do_pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	do_pa(stack_b, stack_a);
}
