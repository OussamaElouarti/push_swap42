/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:16:36 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 11:05:40 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_repetitive(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[j])
        {
            if (i == j)
            {
                j++;
                continue ;
            }
            if (!strcmp(argv[i], argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void add_node(t_stack **stack_a, int value)
{
       t_stack *tmp;

       tmp = malloc(sizeof(t_stack));
       tmp->value = value;
       tmp->next = (*stack_a);
       (*stack_a) = tmp;
}

t_stack *parsing(char **argv, int argc)
{
    int i;
    t_stack *tmp;

    i = argc;
    tmp = NULL;
    while (i >= 0)
        add_node(&tmp, ft_atoi(argv[i--]));
    return (tmp);
}