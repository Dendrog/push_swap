/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_guard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:33:15 by jakim             #+#    #+#             */
/*   Updated: 2024/05/31 21:04:00 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	null_guard(int	*ptr)
{
	if (!ptr)
		exit(1);
}

void	er(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	dup_check(t_stack *a)
{
	int	i;
	int	k;

	i = 0;
	while (i < a->size)
	{
		k = i + 1;
		while (k < a->size)
		{
			if (a->stack[i] == a->stack[k])
				er();
			k++;
		}
		i++;
	}
}