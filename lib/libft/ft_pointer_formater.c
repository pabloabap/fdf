/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_formater.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:51:34 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:04:39 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pointer_formater(unsigned long long int p, int *str_len)
{
	char		*code;

	code = "0123456789abcdef";
	if (p >= 16 && *str_len != -1)
	{
		ft_pointer_formater(p / 16, str_len);
		if (*str_len == -1)
			return ;
		ft_char_formater(code[p % 16], str_len);
		if (*str_len == -1)
			return ;
	}
	else if (*str_len != -1)
	{
		ft_char_formater('0', str_len);
		if (*str_len == -1)
			return ;
		ft_char_formater('x', str_len);
		if (*str_len == -1)
			return ;
		ft_char_formater(code[p], str_len);
		if (*str_len == -1)
			return ;
	}
	return ;
}
