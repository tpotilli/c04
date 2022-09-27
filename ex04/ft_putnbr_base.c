/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:39:38 by tpotilli          #+#    #+#             */
/*   Updated: 2022/09/27 09:27:13 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *tab, int nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		if (tab[i] == tab[j])
			return (1);
		if (tab[i] == '+' || tab[i] == '-')
			return (1);
		j++;
		i++;
	}
	if (nbr <= 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	sizebase;
	int				i;

	sizebase = ft_strlen(base);
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= (-1);
	}
	if (nbr > sizebase - 1)
	{
		ft_putnbr_base(nbr / sizebase, base);
		ft_putnbr_base(nbr % sizebase, base);
	}
	else
		ft_putchar(base[nbr]);
}
