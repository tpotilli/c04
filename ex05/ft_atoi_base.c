/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:10:33 by tpotilli          #+#    #+#             */
/*   Updated: 2022/09/27 09:29:16 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	cpt;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cpt++;
	}
	if (cpt % 2 == 0)
		sign *= (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + result - '0';
		i++;
	}
	return (result * sign);
}