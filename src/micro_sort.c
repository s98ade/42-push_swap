/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:59:06 by sade              #+#    #+#             */
/*   Updated: 2024/01/15 13:06:30 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_3(t_stack **stack)
{
	int	biggest;

	biggest = find_biggest(*stack);
	if (is_sorted(stack))
		return ;
	if ((*stack)->index == biggest)
		do_ra(stack);
	else if ((*stack)->next->index == biggest)
		do_rra(stack);
	if ((*stack)->next->index < (*stack)->index)
		do_sa(stack);
}
