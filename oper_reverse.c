/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:52:20 by jakim             #+#    #+#             */
/*   Updated: 2024/06/07 19:13:01 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *a)
{
	int	i;

	i = a->size;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = a->stack[a->size];
}

void	rra(t_stack *a, t_output **out)
{
	reverse(a);
	lstadd_back(out, lstnew("rra"));
	//ft_printf("rra\n");
}

void	rrb(t_stack *b, t_output **out)
{
	reverse(b);
	lstadd_back(out, lstnew("rrb"));
	//ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_output **out)
{
	reverse(a);
	reverse(b);
	lstadd_back(out, lstnew("rrr"));
	//ft_printf("rrr\n");
}
