/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:56:51 by fde-fram          #+#    #+#             */
/*   Updated: 2020/03/06 12:27:29 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_toupper(int i);
int				ft_tolower(int i);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
int				belong(char c, char const *set);
int				get_next_line(const int fd, char **line);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp_c(const char *s1, const char *s2, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_itoa(int n);
char			*ft_strcpy(char *s1, char *s2);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *s, size_t n);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstmap(t_list *lst,
		void *(*f)(void *), void (*del)(void *));
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
