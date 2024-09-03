/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsabri <tsabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:58:50 by tsabri            #+#    #+#             */
/*   Updated: 2024/09/03 09:36:43 by tsabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0')
	{
		i++;
		j++;
	}
	if (s1[i] == s2[j])
		return (0);
	else
		return (s1[i] - s2[j]);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i++], 1);
	}
}

void	ft_sort_str(char **tab, int size)
{
	int		step;
	int		j;
	char	*key;

	step = 1;
	while (step < size)
	{
		key = tab[step];
		j = step - 1;
		while ((ft_strcmp(key, tab[j]) < 0) && (j >= 0))
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = key;
		step++;
	}
}

int	main(int argc, char **argv)
{
	char	**to_be_sorted;
	int		i;

	if (argc > 1)
	{
		to_be_sorted = &argv[1];
		ft_sort_str(to_be_sorted, argc - 1);
		i = 0;
		while (i < argc - 1)
		{
			ft_putstr(to_be_sorted[i]);
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
