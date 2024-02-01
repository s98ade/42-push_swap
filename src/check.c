/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:59:48 by sade              #+#    #+#             */
/*   Updated: 2024/01/30 12:26:29 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(int num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		++i;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_isnbr(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '-' || nbr[i] == '+' || nbr[i] == ' ')
			++i;
		if (!(ft_isdigit(nbr[i])))
			return (0);
		++i;
	}
	return (1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-') && !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

void	arg_check(char **argv)
{
	int			i;
	long int	tmp;
	int			nb_zero;

	i = 0;
	nb_zero = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error("Error\n");
		if (!ft_isnbr(argv[i]))
			error("Error\n");
		tmp = ft_atoi(argv[i]);
		if (is_dup(tmp, argv, i))
			error("Error\n");
		if (tmp > INT_MAX || tmp < INT_MIN)
			error("Error\n");
		nb_zero += arg_is_zero(argv[i]);
		++i;
	}
	if (nb_zero > 1)
		error("Error\n");
}
