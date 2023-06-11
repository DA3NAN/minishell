/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:18:45 by aait-mal          #+#    #+#             */
/*   Updated: 2023/06/11 16:22:43 by obelaizi         ###   ########.fr       */
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

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	g_data.env = ft_split(get_path(env), ':');
	if (!g_data.env)
		return (ft_print("ERROR\nthere is something with the path", 2), 1);
	signal(SIGINT, sigusr_handler);
	while (1)
		display_prompt();
	return (0);
}
