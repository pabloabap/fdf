/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_formater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:32:18 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:03:26 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char_formater(char c, int *str_len)
{
	int	write_output;

	write_output = write(1, &c, 1);
	if (write_output == -1)
	{
		*str_len = -1;
		return ;
	}
	*str_len = *str_len + write_output;
}
