#ifndef PARSINH_H
# define PARSINH_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct s_stack
{
    int value;
    struct s_stack *next;
}              t_stack;

t_stack* parsing(char **argv, int argc);
int parser(char **argv, int argc);
void	ft_putendl_fd(char *s, int fd);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
int check_repetitive(char **argv);
size_t	ft_strlen(const char *s);
char			*ft_itoa(int n);
int	ft_atoi(const char *str);
void    swap(t_stack **stack);
void rotate(t_stack **stack, int pos);
void push(t_stack **stack_from, t_stack **stack_to);
void    sort_three(t_stack **stack, int pos);
void    sort_five(t_stack **stack, int argc);
int check_sorted(t_stack *stack);
void    rotate_min(t_stack **stack, int argc);
void    sort_big(t_stack **stack, int argc, char **argv);
int search_value(t_stack *stack, int value);
int find_min(t_stack *stack);
void add_node(t_stack **stack_a, int value);

#endif