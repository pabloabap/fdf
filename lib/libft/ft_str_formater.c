/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_formater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:39:52 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:05:14 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_formater(char *s, int *str_len)
{
	int	i;
	int	write_output;

	i = 0;
	write_output = 0;
	if (s == NULL)
	{
		write_output = write(1, "(null)", 6);
		if (write_output != 6)
			*str_len = -1;
		else
			*str_len = *str_len + write_output;
		return ;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_char_formater(s[i], str_len);
			if (*str_len == -1)
				return ;
			i++;
		}
	}
}
