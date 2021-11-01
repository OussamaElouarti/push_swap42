/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:47:49 by oel-ouar          #+#    #+#             */
/*   Updated: 2021/11/01 08:56:04 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

int	ft_check(unsigned long pt, int s)
{
	if (pt > 2147483648 && s == -1)
		return (-1);
	if (pt > 2147483647 && s != -1)
		return (-1);
	return (pt * s);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	j;
	unsigned long long int	t_p;
	int						tt;

	tt = 1;
	j = 0;
	t_p = 0;
	while (*str >= 8 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		tt = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		t_p = t_p * 10 + (unsigned long long int)(*(str + j++) - '0');
	return (ft_check(t_p, tt));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int ft_strisdigit(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-')
        i++;
    while (s[i] != '\0')
    {
        if (s[i] == '-')
            return (0);
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}


int parser(char **argv, int argc)
{
    int i;

    i = 0;
    if (check_repetitive(argv))
        return (1);
    while (argv[i] && ft_strisdigit(argv[i]))
    {
        if (ft_atoi(argv[i]) == -1 && strcmp(ft_itoa(atoi(argv[i])), argv[i]))
            return (1);
        i++;
    }
    if (i == argc)
        return (0);
    else
        return (1);
}