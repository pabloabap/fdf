/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_formater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:03:00 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:05:27 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uint_formater(unsigned int n, int *str_len)
{
	if (n >= 10)
	{
		ft_uint_formater(n / 10, str_len);
		if (*str_len == -1)
			return ;
		ft_char_formater((n % 10 + 48), str_len);
		if (*str_len == -1)
			return ;
	}
	else
	{
		ft_char_formater((n % 10 + 48), str_len);
		if (*str_len == -1)
			return ;
	}
}
