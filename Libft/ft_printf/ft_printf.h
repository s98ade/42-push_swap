/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:09:01 by sade              #+#    #+#             */
/*   Updated: 2023/11/22 10:04:26 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	check_format(va_list args, const char format);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_digit(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex_upper(unsigned int n);
int	ft_print_hex_lower(unsigned long n);
int	ft_print_percent(void);

#endif
