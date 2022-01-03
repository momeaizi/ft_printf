/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:46:16 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/22 10:57:14 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
		i++;
	return (i);
}

void	print(int len, char c, int *count)
{
	while (len-- > 0)
		ft_putchar(c, count);
}

int	get_nbrlen(unsigned long int nbr, int base)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

void	ft_putnbr(unsigned long int nbr, int base, int alpha, int *count)
{
	if (nbr >= (unsigned long int)base)
		ft_putnbr(nbr / base, base, alpha, count);
	if ((nbr % base) >= 10)
		ft_putchar((nbr % base) + alpha, count);
	else
		ft_putchar((nbr % base) + '0', count);
}

void	hex(unsigned int nbr, char c, int *count)
{
	if (c == 'x')
		ft_putnbr(nbr, 16, 87, count);
	else
		ft_putnbr(nbr, 16, 55, count);
}
