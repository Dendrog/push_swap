/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:31:21 by jakim             #+#    #+#             */
/*   Updated: 2024/05/31 21:36:38 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (a->size - 1))
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	search_max(t_stack *a)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = -2147483648;
	while (i < a->size)
	{
		if (a->stack[i] >= max)
		{
			max = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	prepare(t_stack *a, t_stack *b)
{
	int	i;
	int	now;
	
	i = 0;
	now = a->size;
	while (i < now)
	{
		pb(a, b);
		i++;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;
	int	k;
	int	index;
	int	now;

	prepare(a, b);
	i = 0;
	now = b->size;
	while (i < now)
	{
		if(!is_sorted(b))
		{
			index = search_max(b);
			k = 0;
			if (index < b->size / 2)
				while (k < index)
				{
					rb(b);
					k++;
				}
			else
				while (k < b->size - index)
				{
					rrb(b);
					k++;
				}
		}
		pa(a, b);
		i++;
	}
}