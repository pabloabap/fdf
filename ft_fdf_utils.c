/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:05:39 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/02/24 18:51:24 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./lib/libft/libft.h"

void	ft_exit_with_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_inside_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i ++;
	}
}
