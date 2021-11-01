/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:46:24 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 18:57:00 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int find_max(t_stack *stack)
{
    int max;

    max = stack->value;
    stack = stack->next;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}



void sortList(t_stack *stack) {  
    t_stack *current = stack, *index = NULL; 
    int temp;  
    int count = 1;

    while(current != NULL)
    {  
        index = current->next;
        count++;
        while(index != NULL)
        {  
            if(current->value > index->value)
            { 
                temp = current->value;
                current->value = index->value;  
                index->value = temp;  
            }  
            index = index->next;  
        }
        current = current->next;  
    }
} 

int find_mid(int argc, char **argv)
{
    t_stack *current = NULL;
    int count = 0;
    current = parsing(argv, argc);
    sortList(current);
    while (count < argc / 2)
    {
        current = current->next;
        count++;
    }
    return (current->value);
}
void    sort_big(t_stack **stack, int argc, char **argv)
{
    t_stack *stack_b = NULL;
    int max;
    int min;
    int mid;
    
    mid = find_mid(argc, argv);
    max = find_max(*stack);
    min = find_min(*stack);
    while (*stack)
    {
        if ((*stack)->value != max
            && (*stack)->value != min)
        {
            push(stack, &stack_b);
            write(1, "pb\n", 3);
            if (stack_b->value < mid)
            {
                rotate(&stack_b, 1);
                write(1, "rb\n", 3);
            }
        }
        else
            *stack = (*stack)->next;
    }
    while (stack_b)
    {
        printf("%d\n", stack_b->value);
        stack_b = stack_b->next;
    }
}