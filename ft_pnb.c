/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenssou <amenssou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:57:32 by amenssou          #+#    #+#             */
/*   Updated: 2024/11/09 01:50:27 by amenssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	ft_putnbr_uns(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_uns(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_unsigned(unsigned int n)
{
	int	len;

	ft_putnbr_uns(n);
	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_nb(int n)
{
	int	len;

	ft_putnbr(n);
	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
