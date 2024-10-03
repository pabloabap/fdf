/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_formater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:11:51 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/18 21:06:26 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_formater(int i, int *str_len)
{
	int		c;
	char	*p;

	c = 0;
	p = ft_itoa(i);
	if (p == NULL)
		*str_len = -1;
	else
	{
		while (p[c])
		{
			ft_char_formater(p[c], str_len);
			if (*str_len == -1)
			{
				free (p);
				p = 0;
				return ;
			}
			c++;
		}
	}
	free(p);
	p = 0;
	return ;
}
