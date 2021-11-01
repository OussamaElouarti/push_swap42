/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:54:18 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 18:53:12 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    swap(t_stack **stack)
{
    int tmp;

    if (!(*stack) && !(*stack)->next)
        return ;
    else
    {
        tmp = (*stack)->value;
        (*stack)->value = (*stack)->next->value;
        (*stack)->next->value = tmp;
    }
    return ;
}

void rotate(t_stack **stack, int pos)
{
    t_stack *cur;
    t_stack *posNode;
    int count;

    count = 1;
    cur = *stack;
    if (pos == 0 || !(*stack)->next)
        return ;
    while (count < pos && cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    if (cur == NULL)
        return ; 
    posNode = cur;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = *stack;
    *stack = posNode->next;
    posNode->next = NULL;  
}

void push(t_stack **stack_from, t_stack **stack_to)
{
    t_stack *tmp;
    
    if (!(*stack_from))
        return ;
    tmp = malloc(sizeof(t_stack));
    tmp->value = (*stack_from)->value;
    tmp->next = *stack_to;
    *stack_to = tmp;
    free(*stack_from);
    *stack_from = (*stack_from)->next;
    return ;
}