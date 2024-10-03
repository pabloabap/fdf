/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:33:17 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 17:30:11 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./lib/libft/libft.h"

static int	ft_strhex_to_int(char *hex);
static int	ft_strint_to_int(char *number);

int	ft_str_to_int(char *str)
{
	int	num;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		num = ft_strhex_to_int(&(str[2]));
	else
		num = ft_strint_to_int(str);
	return (num);
}

static int	ft_strhex_to_int(char *hex)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			num = num * 16 + hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			num = num * 16 + (hex[i] - 'A' + 10);
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			num = num * 16 + (hex[i] - 'a' + 10);
		else
			ft_exit_with_msg("Invalid hex color");
		i ++;
	}
	return (num);
}

static int	ft_strint_to_int(char *number)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (number[i])
	{
		if (number[i] < '0' && number[i] > '9')
			ft_exit_with_msg("Invalid int color");
		num = num * 10 + number[i] - '0';
		i ++;
	}
	return (num);
}
