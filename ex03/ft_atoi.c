/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:09:06 by tpotilli          #+#    #+#             */
/*   Updated: 2022/09/25 15:36:23 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	resultat;
	int	sign;
	int	cpt;

	resultat = 0;
	i = 0;
	cpt = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cpt++;
		i++;
	}
	if (cpt % 2 != 0)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * sign);
}

int main()
{
	char *tab = "   -+-+123fds45";
	printf("%d",ft_atoi(tab));
}