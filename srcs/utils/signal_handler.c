/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahn <ahn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:14:14 by jooahn            #+#    #+#             */
/*   Updated: 2024/05/09 01:39:18 by ahn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "readline.h"

extern int	g_exit_code;

// SIGINT 받을 시 새 프롬프트 라인 띄우는 함수
void	display_new_prompt(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_code = SIGNAL_OFFSET + SIGINT;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
