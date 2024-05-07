/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:14:14 by jooahn            #+#    #+#             */
/*   Updated: 2023/12/15 20:51:33 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
