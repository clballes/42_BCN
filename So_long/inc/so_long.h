/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:52:23 by clballes          #+#    #+#             */
/*   Updated: 2023/03/22 12:32:53 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define WIDTH 640
#define HEIGHT 480
#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32
#define NUM_FRAMES 2

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char			*line;
	char			**map_array;
	int				rows;
	int				cols;
	int				coll;
	int				x;
	int 			y;
	int				start;
	int				end;
	struct s_map	*next;
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	void			*img_player;
	void			*img_exit;
	void			*img_coll;
	void			*img_1;
	void			*sprites[NUM_FRAMES];
	void			*img_0;
	int				moves;
	int				frame;
}					t_map;
void	ft_open_ber(char **argv);
void	ft_arraymap(t_map *map);
void	check_map_walls(t_map *map, int rows, int cols);
int		ft_strncmp_long(char c, char *s2);
void	has_valid_path(t_map *map, char **cy_map_arr);
//list functions
t_map	*ft_lstnew_long(void	*content);
void	ft_lstadd_back_long(t_map **lst, t_map *new);
t_map	*ft_lstlast_long(t_map *lst);

//print functions
void	print_list(t_map *map);
void	write_error(void);
//windoelin
int		open_window(t_map *map);
void	init_image(t_map *map);
void    printwind(t_map *map);
int		key_hook(int keycode, t_map *map);
int		close_click();
int show_str(t_map *map);
#endif
