/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_any.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:35:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/30 16:34:41 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr_any(const char *s, const char *chars)
{
    if (!s || !chars)
        return (NULL);
    while (*s)
    {
        if (ft_strchr(chars, *s))
            return ((char *)s);
        s++;
    }
    return (NULL);
}
