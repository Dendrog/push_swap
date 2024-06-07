/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:31:21 by jakim             #+#    #+#             */
/*   Updated: 2024/06/07 23:22:58 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (a->size - 1))
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static t_stack	*stack_cpy(t_stack *a, int size)
{
	t_stack	*st;
	int	i;
	
	i = 0;
	st = (t_stack *)malloc(sizeof(t_stack));
	st->size = size;
	st->stack = (int *)malloc(sizeof(int) * (size + 5));
	null_guard(st->stack);
	while (i < size)
	{
		st->stack[i] = a->stack[i];
		i++;
	}
	return (st);
}

static void	search_pivot(t_stack *st, int size, int *p1, int *p2)
{
	int	i;
	int	k;
	int	tmp;
	t_stack *a;

	a = stack_cpy(st, size);
	i = 0;
	while (i < size - 1)
	{
		k = 0;
		while (k < size - 1 - i)
		{
			if (a->stack[k] > a->stack[k + 1])
			{
				tmp = a->stack[k];
				a->stack[k] = a->stack[k + 1];
				a->stack[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
	*p1 = a->stack[size / 3];
	*p2 = a->stack[size / 3 * 2 - 1];
	free(a->stack);
	free(a);
}

static void	mini_sort(t_stack *a, int size, t_output **out)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a->stack[0] > a->stack[1])
			sa(a, out);
	}
	else if (size == 3)
	{
		if (size == a->size)
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
				rra(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a, out);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
				rra(a, out);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
				ra(a, out);
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
			}
		}
		else
		{
			if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
				rra(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2] && a->stack[1] < a->stack[2])
				sa(a, out);
			else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				ra(a, out);
				sa(a, out);
				rra(a, out);
				sa(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			{
				sa(a, out);
				ra(a, out);
				sa(a, out);
				rra(a, out);
			}
			else if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2] && a->stack[1] > a->stack[2])
			{
				sa(a, out);
				ra(a, out);
				sa(a, out);
				rra(a, out);
				sa(a, out);
			}
		}
	}
}

void	sort(t_stack *a, t_stack *b, int size, int p1, int p2, int s, t_output **out)
{
	int	r;
	//int	s;
	int	m;
	int	i;
	int	tmp;
	int	count;
	//int p1;
	//int p2;

	i = 0;
	r = 0;
	//s = 0;
	m = 0;
	if (size <= 3)
	{
		mini_sort(a, size, out);
		return ;
	}
	if (!is_sorted(a))
	{
	//	return ;
	
	if (s == 0)
		search_pivot(a, size, &p1, &p2);
	count = 0;
	while (i < size)
	{
		if (a->stack[0] < p1)
		{
			pb(a, b, out);
			count++;
			//rb(b);
			s++;
		}
		else if (a->stack[0] <= p2)
		{
			while (count)
			{
				rb(b, out);
				count--;
			}
			pb(a, b, out);
			m++;
		}
		else
		{
			if (count)
			{
				rr(a, b, out);
				count--;
			}
			else
				ra(a, out);
			r++;
		}
		i++;
	}
	while (count)
	{
		rb(b, out);
		count--;
	}
	}
	i = 0;
	if (a->size != r)
	{
		while (i < r)
		{
			rra(a, out);
			i++;
		}
	}
	//search_pivot(a, r, &p1, &p2);
	sort(a, b, r, p1, p2, 0, out);
	i = 0;
	if (m > 4)
	{
		tmp = 0;
		search_pivot(b, m, &p1, &p2);
		while (i < m)
		{
			if (b->stack[0] < p1)
			{
				rb(b, out);
				tmp++;
			}
			else
				pa(a, b, out);
			i++;
		}
		//search_pivot(a, m, &p1, &p2);
		sort(a, b, m - tmp, p1, p2, tmp, out);
	}
	else
	{
		while (i < m)
		{
			pa(a, b, out);
			i++;
		}
		sort(a, b, m, p1, p2, 0, out);
	}
	i = 0;
	if (s > 4)
	{
		//ft_printf("1");
		i = 0;
		while (i < s)
		{
			reverse(b);
			i++;
		}
		search_pivot(b, s, &p1, &p2);
		i = 0;
		while (i < s)
		{
			rotate(b);
			i++;
		}
		i = 0;
		if (s == b->size)
		{
			tmp = 0;
			while (i < s)
			{
				if (b->stack[0] < p1)
				{
					rb(b, out);
					tmp++;
				}
				else
					pa(a, b, out);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < s)
			{
				rrb(b, out);
				//pa(a, b);
				i++;
			}
			i = 0;
			tmp = 0;
			while (i < s)
			{
				if (b->stack[0] < p1)
				{
					rb(b, out);
					tmp++;
				}
				else
					pa(a, b, out);
				i++;
			}
		}
		//search_pivot(a, s, &p1, &p2);
		sort(a, b, s - tmp, p1, p2, tmp, out);	
	}
	else
	{
		//ft_printf("2");
		if (s == b->size)
		{
			while (i < s)
			{
				pa(a, b, out);
				i++;
			}
		}
		else
		{
			while (i < s)
			{
				rrb(b, out);
				pa(a, b, out);
				i++;
			}
		}
		//search_pivot(a, s, &p1, &p2);
		sort(a, b, s, p1, p2, 0, out);	
	}
}

/*static int	search_max(t_stack *a)
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
}*/
/*


void	first_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	m;
	int	k;

	i = 0;
	m = stack_cpy(a);
	ft_printf("%d",m);
	k = a->size;
	while (i < k)
	{
		if (a->stack[0] <= m)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	second_sort(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		
	}
}*/