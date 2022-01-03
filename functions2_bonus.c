/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:14:44 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 16:37:46 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_address(int *count, va_list	ptr, t_struct *strc)
{
	unsigned long int	nbr;
	int					nbr_len;

	nbr = va_arg(ptr, unsigned long int);
	nbr_len = get_nbrlen(nbr, 16) + 2;
	if (!strc->minus)
		print(strc->minfild - nbr_len, ' ', count);
	ft_putstr("0x", count);
	ft_putnbr(nbr, 16, 87, count);
	if (strc->minus)
		print(strc->minfild - nbr_len, ' ', count);
}

void	ft_unsigned(int *count, va_list ptr, t_struct *strc)
{
	unsigned int	nbr;
	int				var;
	int				nbr_len;

	nbr = (unsigned int)va_arg(ptr, unsigned int);
	nbr_len = get_nbrlen(nbr, 10);
	if (!strc->dot && !nbr)
		nbr_len = 0;
	var = nbr_len;
	if (strc->dot > nbr_len)
		var = strc->dot;
	if (strc->minfild && !strc->minus)
		if (!strc->minus)
			print(strc->minfild - var, ' ', count);
	dot_zero(nbr_len, count, strc);
	if (!(!nbr && !strc->dot))
		ft_putnbr(nbr, 10, 0, count);
	if (strc->minus)
		print(strc->minfild - var, ' ', count);
}

void	ft_hexa(char c, int *count, va_list	ptr, t_struct *strc)
{
	unsigned int	nbr;
	int				var;
	int				nbr_len;

	nbr = (unsigned int)va_arg(ptr, unsigned int);
	nbr_len = get_nbrlen(nbr, 16);
	if (!strc->dot && !nbr)
		nbr_len = 0;
	var = nbr_len;
	if (strc->dot > nbr_len)
		var = strc->dot;
	if (strc->hash && nbr)
	{
		strc->zero -= 2;
		strc->minfild -= 2;
	}
	if (!strc->minus)
		print(strc->minfild - var, ' ', count);
	if (strc->hash && nbr)
		hash(c, count);
	dot_zero(nbr_len, count, strc);
	if (!(!nbr && !strc->dot))
		hex(nbr, c, count);
	if (strc->minus)
		print(strc->minfild - var, ' ', count);
}

void	hash(char c, int *count)
{
	ft_putchar('0', count);
	ft_putchar(c, count);
}
