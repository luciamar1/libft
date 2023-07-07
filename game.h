/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:49 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/28 16:34:37 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_minilib
 {
	void	*mlx_pointer;
	t_window	*window;
    int			columns;
    int			rows;
	t_image		sprite;
	t_vector	sprite_position;
	// … etc
}				t_minilib;


#endif
