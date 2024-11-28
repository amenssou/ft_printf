/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenssou <amenssou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:44:55 by amenssou          #+#    #+#             */
/*   Updated: 2024/11/09 01:46:01 by amenssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_char(int c);
int	ft_string(char *str);
int	ft_strlen(char *s);
int	ft_nb(int n);
int	ft_unsigned(unsigned int n);
int	ft_hexa_min(unsigned int n);
int	ft_hexa_maj(unsigned int n);
int	ft_pointer(unsigned long n);

#endif
