/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:01 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/04 19:06:38 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>


typedef struct s_room
{
	char				*name;
	int					x;
	int					y;
	int					numberOfNeighbors;
	int					visited;
	struct s_room		*parent;
	struct s_room		**neighbors;
}	t_room;

typedef struct s_relation
{
	char				*lRoom;
	char				*rRoom;
	struct s_relation	*next;
}	t_relation;

typedef struct s_queue
{
    t_room	**queue;
    int		l;
    int		r;
	int		size;
}	t_queue;

typedef struct s_global
{
	int				numberOfAnts;
	int				numberOfRooms;
	int				numberOfRelations;
	t_queue			*queue;
	t_relation		*relations;
	t_room			*graph;
	t_room			*start;
	t_room			*end;
}	t_global;

extern t_global	g_data;

int			ft_isalpha(int _c);
int			ft_isdigit(int _c);
int			ft_isalnum(int _c);
int			ft_isascii(int _c);
int			ft_isprint(int _c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char*s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		parser(char *fileName);
t_queue		*createQueue(int size);
int			queueIsFull(t_queue *q);
int			queueIsEmpty(t_queue *q);
void		enqueue(t_queue	*q, t_room* room);
t_room		*dequeue(t_queue* q);
void		bfs();

#endif
