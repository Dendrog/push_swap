/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:42:27 by jakim             #+#    #+#             */
/*   Updated: 2024/05/31 21:10:49 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size - 1;
	if (!b->size)
		return ;
	if (a->size)
	{
		while (i >= 0)
		{
			a->stack[i + 1] = a->stack[i];
			i--;
		}
	}
	a->stack[0] = b->stack[0];
	a->size++;
	i = 0;
	while (i + 1 < b->size)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb\n");
}
