/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_formater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:51:16 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:04:10 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hex_formater(unsigned int n, int *str_len)
{
	char	*code;

	code = "0123456789abcdef";
	if (n >= 16)
	{
		ft_hex_formater(n / 16, str_len);
		if (*str_len == -1)
			return ;
		ft_char_formater(code[n % 16], str_len);
		if (*str_len == -1)
			return ;
	}
	else
	{
		ft_char_formater(code[n % 16], str_len);
		if (*str_len == -1)
			return ;
	}
}
