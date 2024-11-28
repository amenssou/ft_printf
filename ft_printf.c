/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenssou <amenssou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:49:59 by amenssou          #+#    #+#             */
/*   Updated: 2024/11/09 16:32:40 by amenssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(const char *str, va_list args, int i)
{
	int	cpt;

	cpt = 0;
	if (str[i] == '%' && str[i + 1] == '%')
	{
		write(1, &str[i], 1);
		cpt++;
	}
	else if (str[i] == '%' && str[i + 1] == 'c')
		cpt = cpt + ft_char(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 's')
		cpt = cpt + ft_string(va_arg(args, char *));
	else if ((str[i] == '%' && str[i + 1] == 'd')
		|| (str[i] == '%' && str[i + 1] == 'i'))
		cpt = cpt + ft_nb(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		cpt = cpt + ft_unsigned(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'x')
		cpt = cpt + ft_hexa_min(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'X')
		cpt = cpt + ft_hexa_maj(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'p')
		cpt = cpt + ft_pointer(va_arg(args, unsigned long));
	return (cpt);
}

int	ft_printf(const char *str, ...)
{
	int		cpt;
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] != '%' )
		{
			cpt++;
			write(1, &str[i], 1);
		}
		else
		{
			cpt = cpt + ft_format(str, args, i);
			i++;
		}
		i++;
	}
	va_end(args);
	return (cpt);
}
/*
#include <stdio.h>
int main()
{
	//void *p = "abc";
	//int aa;
	//ft_printf("Bonjour je m'appelle : %s et j'ai %d ans.\nMa
	//premiere lettre est:  %c %c %c","Ayman", 17,'A', 'K', 'O');
	//ft_printf("%s", (char *) NULL);
	 printf("%%%%\n");
	 ft_printf("%%%%");
	 //printf("%p\n", p);
	 //ft_printf("%p", p);
	 //ft_printf("%X",11);
	//printf("%d", ft_printf("%s", (char *) NULL));
	//printf(" %s %d  %c  %u %x %X\n","Aym", 17,'A', 245, 742, 17);
	//printf("%d", a);
}*/
