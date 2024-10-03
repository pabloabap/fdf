/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:35:07 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:04:58 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_formater_detect(char const *f, va_list args, int i, int *str_len)
{
	if (f[i] == 'c')
		ft_char_formater(va_arg(args, int), str_len);
	else if (f[i] == 's')
		ft_str_formater(va_arg(args, char *), str_len);
	else if (f[i] == 'i' || f[i] == 'd')
		ft_int_formater(va_arg(args, int), str_len);
	else if (f[i] == 'p')
		ft_pointer_formater(va_arg(args, unsigned long long int), str_len);
	else if (f[i] == 'u')
		ft_uint_formater(va_arg(args, unsigned int), str_len);
	else if (f[i] == 'x')
		ft_hex_formater(va_arg(args, unsigned int), str_len);
	else if (f[i] == 'X')
		ft_upperhex_formater(va_arg(args, unsigned int), str_len);
	else if (f[i] == '%')
		ft_char_formater('%', str_len);
}

int	ft_printf(char const *f, ...)
{
	va_list	args;
	int		str_len;
	int		i;

	str_len = 0;
	i = 0;
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%')
			ft_formater_detect(f, args, ++i, &str_len);
		else
		{
			if (write(1, &(f[i]), 1) != 1)
				return (-1);
			str_len ++;
		}
		if (str_len < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (str_len);
}
