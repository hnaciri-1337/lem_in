/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:30:38 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 01:06:59 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	fatal_error(char *str) {
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 2);
	exit (1);
}
