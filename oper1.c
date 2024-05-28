/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:54:48 by jakim             #+#    #+#             */
/*   Updated: 2024/05/28 19:42:19 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a)
{
	int	tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	sa(int *a)
{
	swap(a);
	ft_printf("sa");
}

void	sb(int *b)
{
	swap(b);
	ft_printf("sb");
}

void	ss(int *a, int *b)
{
	swap(a);
	swap(b);
	ft_printf("ss");
}