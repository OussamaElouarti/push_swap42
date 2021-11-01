/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:17:09 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 16:07:13 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

int search_value(t_stack *stack, int value)
{
    int i;

    i = 0;
    while (stack->next)
    {
        if (stack->value == value)
            break ;
        stack = stack->next;
        i++;
    }
    return (i);
}

int find_min(t_stack *stack)
{
    int min;

    min = stack->value;
    stack = stack->next;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

void    sort_three(t_stack **stack, int pos)
{
    if (check_sorted(*stack))
        return ;
    if ((*stack)->value > (*stack)->next->value
        || ((*stack)->value < (*stack)->next->value 
        && (*stack)->value < (*stack)->next->next->value))
    {
        if ((*stack)->value > (*stack)->next->value
            && (*stack)->next->value < (*stack)->next->next->value
            && (*stack)->value > (*stack)->next->next->value)
        {
            rotate(stack, 1);
            write(1, "ra\n", 3);
            return ;
        }
        swap(stack);
        write(1, "sa\n", 3);
        if (((*stack)->value > (*stack)->next->value))
        {
            rotate(stack, 1);
            write(1, "ra\n", 3);
        }
        else if ((*stack)->value < (*stack)->next->value
            && (*stack)->next->value > (*stack)->next->next->value)
        {
            rotate(stack, pos);
            write(1, "rra\n", 4);
        }
    }
    else
    {
        rotate(stack, pos);
        write(1, "rra\n", 4);
    }
    return ;
}

void    rotate_min(t_stack **stack, int argc)
{
    int counter;
    
        counter = search_value(*stack, find_min(*stack));
    if (counter <= argc / 2)
    {
        while (counter)
        {
            rotate(stack, 1);
            write(1, "ra\n", 3);
            counter--;
        }
    }
    else
    {
        while (counter <= argc)
        {
            rotate(stack, argc);
            write(1, "rra\n", 4);
            counter++;
        }
    }
}

void    sort_five(t_stack **stack, int argc)
{
    t_stack *stack_b;

    rotate_min(stack, argc);
    push(stack, &stack_b);
    write(1, "pb\n", 3);
    if (argc == 4)
    {
        rotate_min(stack, argc - 1);
        push(stack, &stack_b);
        write(1, "pb\n", 3);
    }
    if (argc == 4)
    {
        sort_three(stack, argc- 2);
        push(&stack_b, stack);
        write(1, "pa\n", 3);
    }
    else
        sort_three(stack, argc- 1);
    push(&stack_b, stack);
    write(1, "pa\n", 3);
}