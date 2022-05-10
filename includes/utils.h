/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:20:32 by emtran            #+#    #+#             */
/*   Updated: 2022/05/10 18:36:26 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 1

/*			UTILS_DIGITS		*/

int					ft_atoi(const char *str);
int					ft_nbrlen(int n);
unsigned long long	ft_atoull(const char *str);

/*			UTILS_GET_NEXT_LINE			*/

char				*ft_pushinyourline(char *save);
int					ft_secu_av_tout(char *save);
int					ft_n_ta_race(char *str);
char				*ft_savebryan(char *save);
int					get_next_line(int fd, char **line);

/*			UTILS_MEM			*/

void				*ft_memset(void *s, int a, int c);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memcpy_with_one_char(void *dest, const char c, \
					size_t count);
char				*ft_strcalloc(size_t size);
void				*ft_calloc(size_t num, size_t size);

/*			UTILS_STR			*/

int					ft_strlen(char *str);
int					ft_strcmp(char *str1, char *str2);
void				ft_strcpy(char *dest, char *src);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strnstr(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(char *str);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
void				ft_strncpy(char *dest, char *src, int n);
char				*ft_substr(char *s, int start, int len);

/*			UTILS_WRITE			*/

void				ft_putnbr(int nb, int fd);
void				ft_putstr(char *str, int fd);
void				ft_putchar(char c, int fd);

#endif