/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:01:52 by mdaillet          #+#    #+#             */
/*   Updated: 2021/12/25 19:22:56 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_info	info;
	t_check	check;

	if (ac == 2)
	{
		if (ft_check_file(av[1], &check) == SUCCESS)
		{
			ft_init(&info);
			ft_parse(&info, av[1]);
			ft_init_dir(&info);
			ft_colors(&info);
			ft_cub3d(&info);
		}
	}
	else
	{
		printf("Error\nUse : ./cub3d map.cub\n");
		return (0);
	}
	//ft_free_all(&info);
	return (0);
}
