/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:58:56 by clballes          #+#    #+#             */
/*   Updated: 2023/07/10 12:58:57 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_not_digit(argv[i]) != 0)
		{
			write(2, "there are letters\n", 18);
			return (1);
		}
		if (max_int(argv[i]) != 0)
		{
			write(2, "number above maxim int\n", 23);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*thread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 == 0)
		usleep_time(philo->all->time_to_eat);
	while (philo->all->dead == 0)
	{
		if (to_think(philo) != 0 || to_eat(philo) != 0 || to_sleep(philo) != 0)
			print(5, philo);
	}
	return (NULL);
}

void	philo_join_free(t_all *all, pthread_t *id)
{
	int	i;

	i = 0;
	while (all->n_philo > i)
	{
		if (pthread_join(id[i], NULL) != 0)
			return ;
		i++;
	}
	free(id);
	free_mutex(all);
	free(all->philo);
	free(all);
}

void	start_philo(t_all *all)
{
	pthread_t		*id;
	int				i;

	i = 0;
	id = malloc(sizeof(pthread_t) * all->n_philo);
	if (!id)
		return ;
	pthread_mutex_init(&all->print, NULL);
	while (i < all->n_philo)
	{
		if (pthread_create(&id[i], NULL, thread_routine, &all->philo[i]) != 0)
		{
			free(id);
			return ;
		}
		i++;
	}
	is_dead(all);
	philo_join_free(all, id);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (argc == 5 || argc == 6)
	{
		if (parsing(argv) != 0)
			return (0);
		init(argv, all);
		start_philo(all);
	}
	else
		write(2, "Missing arguments\n", 19);
	return (0);
}
