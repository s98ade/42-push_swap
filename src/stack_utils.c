/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:34:01 by sade              #+#    #+#             */
/*   Updated: 2024/01/30 12:50:44 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		++count;
	}
	return (count);
}

t_stack	*get_stack_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	add_stack_last(t_stack **stack, t_stack *new)
{
	if (!new)
		return (1);
	if (*stack)
		get_stack_last(*stack)->next = new;
	else
		*stack = new;
	return (0);
}

t_stack	*get_before_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next && stack->next != get_stack_last(stack))
		stack = stack->next;
	return (stack);
}
