/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenssou <amenssou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:19:43 by amenssou          #+#    #+#             */
/*   Updated: 2024/11/09 01:48:06 by amenssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_char(int c)
{
	char	a;

	a = (char)c;
	write(1, &a, 1);
	return (1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (i < ft_strlen(str))
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}
/*
#include <stdio.h>
int main ()
{
	char *c = "kaka";
	int i = ft_strlen(c);
	printf("%d", i);
}*/
