/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/16 15:45:33 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define GNL_ERROR 0
# define GNL_OK 1

typedef struct s_gnl
{
	char	*data;
	size_t	len;
	size_t	cap;
}	t_gnl;

void	ft_memcpy_gnl(char *dst, const char *src, size_t n);
char	*ft_clear_state(t_gnl **state);
int		ft_init_state(t_gnl **state);
int		ft_ensure_capacity(t_gnl *state, size_t need);
size_t	ft_line_len(t_gnl *state);
char	*get_next_line(int fd);

#endif
