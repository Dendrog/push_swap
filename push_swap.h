/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:14:18 by jakim             #+#    #+#             */
/*   Updated: 2024/05/28 19:46:11 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_stack {
	int	*row;
	int	size;
}				t_stack;

void	null_guard(int	*ptr);
void	er(void);
int	*make_stack_1(char *argv, int *l);
char	*ft_atoi2(char *nptr, int	*r);
int	*make_stack_2(int argc, char *argv[], int *l);

#endif