/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/05/27 21:17:50 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	*a;
	int	l;
	//int	*b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
	{
		a = make_stack_1(argv[1], &l);
		int q = 0;
		while (1)
		{
			if (q < l)
				ft_printf("%d ",a[q++]);
			else
				break;
		}
	}
}