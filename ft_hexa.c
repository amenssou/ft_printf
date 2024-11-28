/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenssou <amenssou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:29:06 by amenssou          #+#    #+#             */
/*   Updated: 2024/11/09 16:38:52 by amenssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	nb_len_hexa(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_hexa_min(unsigned int n)
{
	int		res;
	char	*str;
	int		cpt;
	char	*h;

	res = 0;
	str = "0123456789abcdef";
	cpt = nb_len_hexa(n);
	h = malloc(sizeof(char) * (cpt + 1));
	if (!h)
		return (0);
	h[cpt] = '\0';
	while (cpt > 0)
	{
		res = n % 16;
		h[--cpt] = str[res];
		n = n / 16;
	}
	cpt = 0;
	while (h[cpt])
		write(1, &h[cpt++], 1);
	free(h);
	return (cpt);
}

int	ft_hexa_maj(unsigned int n)
{
	int		res;
	char	*str;
	int		cpt;
	char	*h;

	res = 0;
	str = "0123456789ABCDEF";
	cpt = nb_len_hexa(n);
	h = malloc(sizeof(char) * (cpt + 1));
	if (!h)
		return (0);
	h[cpt] = '\0';
	while (cpt > 0)
	{
		res = n % 16;
		h[--cpt] = str[res];
		n = n / 16;
	}
	cpt = 0;
	while (h[cpt])
		write(1, &h[cpt++], 1);
	free(h);
	return (cpt);
}

static int	nb_len_pointer(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long n)
{
	int		res;
	char	*str;
	int		cpt;
	char	*h;

	res = 0;
	str = "0123456789abcdef";
	cpt = nb_len_pointer(n);
	h = malloc(sizeof(char) * (cpt + 1));
	if (!h)
		return (0);
	h[cpt] = '\0';
	while (cpt > 0)
	{
		res = n % 16;
		h[--cpt] = str[res];
		n = n / 16;
	}
	cpt = 0;
	write(1, "0x", 2);
	while (h[cpt])
		write(1, &h[cpt++], 1);
	free(h);
	return (cpt + 2);
}
/*
#include <stdio.h>
//test conversion hexa
int main ()
{
	//int a =  44252;
	//int res = 0;
	while (a / 16)
	{
		res = 16 * (a / 16);
		a = a / 16;
	int i = 0;
	while (i < 4){
		printf ("%d   ",a % 16 );
		i++;
		a = a / 16;
	
	ft_phexa(10217);
}*/
