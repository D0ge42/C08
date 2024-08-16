/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:19:41 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/16 17:20:23 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	char	*orig;

	i = ft_strlen(src);
	dest = (char *)malloc(i + 1);
	if (!dest)
		return (NULL);
	orig = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (orig);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*elements;
	
	i = 0;
	elements = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!elements)
		return (NULL);
	while (i < ac)
	{
		elements[i].size = ft_strlen(av[i]);
		elements[i].str = av[i];
		elements[i].copy = ft_strdup(av[i]);
		i++;
	}
	elements[i].str = 0;
	return (elements);
}
