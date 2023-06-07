/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:18:45 by aait-mal          #+#    #+#             */
/*   Updated: 2023/06/07 17:31:05 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigusr_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\nminishell# ", 12);
	}
}

void	display_prompt(void)
{
	char	*input;

	input = readline("minishell# ");
	if (!input)
		exit (0);
	printf("You entered : %s\n", input);
	free(input);
}

int	main(void)
{
	signal(SIGINT, sigusr_handler);
	while (1)
	{
		display_prompt();
	}
	return (0);
}
