/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:59:40 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/19 09:50:39 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list	args, const char *format, int *ret)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), ret);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), ret);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_base((va_arg(args, int)), "0123456789", ret);
	else if (*format == 'u')
		ft_putnbr_b_un((va_arg(args, unsigned int)), "0123456789", ret);
	else if (*format == 'x')
		ft_putnbr_b_un((va_arg(args, unsigned int)), "0123456789abcdef", ret);
	else if (*format == 'X')
		ft_putnbr_b_un((va_arg(args, unsigned int)), "0123456789ABCDEF", ret);
	else if (*format == '%')
		*ret += write(1, "%", 1);
	else if (*format == 'p')
		ft_pnbr_p((unsigned long)va_arg(args, void *), "0123456789abcdef", ret);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret += ft_check_type(args, format, &ret);
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}
