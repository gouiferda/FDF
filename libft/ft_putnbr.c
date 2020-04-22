/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int nb)
{
	unsigned int number;

	if (nb < 0)
	{
		ft_putchar('-');
		number = -nb;
	}
	else
	{
		number = nb;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	else if (number < 10)
	{
		ft_putchar(number + '0');
	}
}
