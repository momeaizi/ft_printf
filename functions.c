/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:24:59 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 11:36:00 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal(int *count, va_list ptr, t_struct *strc)
{
	int	nbr;

	nbr = (int)va_arg(ptr, int);
	if (nbr < 0)
		ft_negative(nbr, get_nbrlen((unsigned int)-nbr, 10) + 1, count, strc);
	else
		ft_positive(nbr, get_nbrlen(nbr, 10), count, strc);
}

void	ft_negative(int nbr, int nbr_len, int *count, t_struct *strc)
{
	int	var;

	var = nbr_len;
	if (strc->dot >= nbr_len)
		var = strc->dot + 1;
	if (strc->minfild && !strc->minus)
		if (!strc->minus)
			print(strc->minfild - var, ' ', count);
	ft_putchar('-', count);
	if (strc->dot >= 0 || strc->zero)
	{
		if (strc->dot >= 0)
			print(strc->dot - nbr_len + 1, '0', count);
		else
			print(strc->zero - nbr_len, '0', count);
	}
	ft_putnbr((unsigned int)-nbr, 10, 0, count);
	if (strc->minus)
		print(strc->minfild - var, ' ', count);
}

void	ft_positive(int nbr, int nbr_len, int *count, t_struct *strc)
{
	char	c;
	int		var;

	c = '+';
	if (!strc->dot && !nbr)
		nbr_len = 0;
	var = nbr_len;
	if (strc->dot > nbr_len)
		var = strc->dot;
	c = splus(c, strc);
	if (strc->minfild && !strc->minus)
		if (!strc->minus)
			print(strc->minfild - var, ' ', count);
	if (strc->plus || strc->space)
		ft_putchar(c, count);
	dot_zero(nbr_len, count, strc);
	if (!(!nbr && !strc->dot))
		ft_putnbr(nbr, 10, 0, count);
	if (strc->minus)
		print(strc->minfild - var, ' ', count);
}

char	splus(char c, t_struct *strc)
{
	if (strc->plus || strc->space)
	{
		if (strc->space)
			c = ' ';
		if (strc->zero)
			strc->zero--;
		strc->minfild--;
	}
	return (c);
}

void	dot_zero(int nbr_len, int *count, t_struct *strc)
{
	if (strc->dot >= 0 || strc->zero)
	{
		if (strc->dot >= 0)
			print(strc->dot - nbr_len, '0', count);
		else
			print(strc->zero - nbr_len, '0', count);
	}
}
