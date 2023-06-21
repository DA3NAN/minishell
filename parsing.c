/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:42:18 by obelaizi          #+#    #+#             */
/*   Updated: 2023/06/12 12:13:59 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokens(char *str)
{
	g_data.tkns.pipe = count_str(str, "|");
	g_data.tkns.heredoc = count_str(str, "<<");
	g_data.tkns.append = count_str(str, ">>");
	g_data.tkns.out = count_str(str, ">");
	g_data.tkns.in = count_str(str, "<");
}

void	parse(char *str)
{
	if (count_str(str, "'") % 2 || count_str(str, "\"") % 2)
	{
		printf("Dude close ur things\n");
		exit(1);
	}
}
