/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:56:39 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 18:51:42 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

int check_sorted(t_stack *stack)
{
    while (stack)
    {
        if (stack->next && stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack * stack_a;
    t_stack * stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (parser(++argv, argc - 1) || argc == 1)
    {
        ft_putendl_fd("wrong args", 2);
        return (1);
    }
    stack_a = parsing(argv, argc - 2);
    if (check_sorted(stack_a))
        return (1);
    if (argc == 3)
    {
        swap(&stack_a);
        write(1, "sa\n", 3);
    }
    if (argc == 4)
        sort_three(&stack_a, argc - 2);
    if (argc == 5 || argc == 6)
        sort_five(&stack_a, argc - 2);
    if (argc > 6)
        sort_big(&stack_a, argc - 2, argv);
    printf("stack A\n");
    while (stack_a)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    return (0);
}