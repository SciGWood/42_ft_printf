/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:35:54 by gdetourn          #+#    #+#             */
/*   Updated: 2023/10/23 13:35:56 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long int nbr, char *base, int *ret)
{
	int			base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		*ret += write(1, "-", 1);
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base((nbr / base_len), base, ret);
		ft_putchar(base[nbr % base_len], ret);
	}
	else if (nbr < base_len)
		ft_putchar(base[nbr], ret);
}

void	ft_putnbr_b_un(unsigned int nbr, char *base, int *ret)
{
	unsigned int	base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbr_base((nbr / base_len), base, ret);
		ft_putchar(base[nbr % base_len], ret);
	}
	else if (nbr < base_len)
		ft_putchar(base[nbr], ret);
}

void	ft_pnbr_p(unsigned long nbr, char *base, int *ret)
{
	unsigned long	base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (!nbr)
	{
		*ret += write (1, "(nil)", 5);
		return ;
	}
	*ret += write(1, "0x", 2);
	if (nbr >= base_len)
	{
		ft_putnbr_base((nbr / base_len), base, ret);
		ft_putchar(base[nbr % base_len], ret);
	}
	else if (nbr < base_len)
		ft_putchar(base[nbr], ret);
}
