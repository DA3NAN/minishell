/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:55:59 by obelaizi          #+#    #+#             */
/*   Updated: 2023/06/08 21:42:27 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char *str, int flag)
{
	printf("%s", str);
	if (flag)
		printf("\n");
}

void	cd(char *path)
{
	if (chdir(path) == -1)
		perror("chdir");
}

void	pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd");
}

void	export(char *argument)
{
	char	*equal_sign;
	char	*nm_vr;
	char	*vl_vr;
	int		i;
	char	*updt_vr;

	i = -1;
	equal_sign = ft_strchr(argument, '=');
	if (equal_sign == NULL)
		return ;
	*equal_sign = '\0';
	*nm_vr = argument;
	*vl_vr = equal_sign + 1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], nm_vr, fr_strlen(nm_vr))
			&& env[i][ft_strlen(nm_vr)] == '=')
		{
			updt_vr = malloc(ft_strlen(nm_vr) + ft_strlen(vl_vr) + 2);
			env[i] = updt_vr;
			return ;
		}
	}
	updt_vr = malloc(ft_strlen(nm_vr) + ft_strlen(vl_vr) + 2);
	return (env[i] = updt_vr, env[i + 1] = NULL);
}

void	unset(char *s)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], s, ft_strlen(s)) && env[i][ft_strlen(s)] == '=')
		{
			j = i - 1;
			while (env[++j])
				env[j] = env[j + 1];
			return ;
		}
	}
}
