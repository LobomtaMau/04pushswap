/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:53:33 by mbaptist          #+#    #+#             */
/*   Updated: 2023/07/14 16:57:11 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_count(char *s, char space)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == space)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != space)
				s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = ft_word_count(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

/*char	**ft_split(char *str, char space)
{
	int		k;
	int		j;
	int		wc;
	int		wlen;
	char	**res;

	k = 0;
	wc = ft_word_count(str, space);
	res = (char **)malloc(sizeof(char *) * wc + 1);
	if (!res)
		return (NULL);
	while (k < wc)
	{
		j = 0;
		while (*str && *str == space)
			str++;
		wlen = ft_word_len(str, space);
		res[k] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!res[k])
			return (NULL);
		while (*str && *str != space)
			res[k][j++] = *(str++);
		res[k][j] = '\0';
		k++;
	}
	res[k] = NULL;
	return (res);
}

static int	ft_word_len(char *s, char space)
{
	int	len;

	len = 0;
	while (*s && *s != space)
	{
		len++;
		s++;
	}
	return (len);
}*/