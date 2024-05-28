/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:04 by jakim             #+#    #+#             */
/*   Updated: 2024/05/28 18:05:46 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int	*a;
	int	l;
	int	*b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		a = make_stack_1(argv[1], &l);
	if (argc > 2)
		a = make_stack_2(argc, argv, &l);
	b = (int *)malloc(sizeof(int) * (l + 5));
}