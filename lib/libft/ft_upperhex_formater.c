/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperhex_formater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:57:48 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:05:45 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_upperhex_formater(unsigned int n, int *str_len)
{
	char	*code;

	code = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_upperhex_formater(n / 16, str_len);
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
