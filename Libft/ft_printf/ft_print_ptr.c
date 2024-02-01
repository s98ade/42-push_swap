/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:14:26 by sade              #+#    #+#             */
/*   Updated: 2023/11/23 13:32:19 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_ptr(unsigned long ptr)
{
	int	count;
	int	add;

	count = 0;
	add = write (1, "0x", 2);
	if (add == -1)
		return (-1);
	count = (add + ft_print_hex_lower (ptr));
	if (count == -1)
		return (-1);
	return (count);
}
