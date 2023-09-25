/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:46:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/04 16:22:12 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	length;

	if (lst == NULL)
	{
		return (0);
	}
	length = 1;
	while (lst->next != NULL)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}
