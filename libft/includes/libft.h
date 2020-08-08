/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:51:11 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/21 16:19:26 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <wchar.h>

# ifdef __linux__
#  include <stdint.h>
# endif

/*
**	CONSTANTS +=================================================================
*/

# define HEX_BASE "0123456789abcdef"

/*
**	DATA TYPES =================================================================
*/

# define GNL_BUFF_SIZE 512

enum			e_gnlstatus
{
	READ_NONE,
	READ_LINE,
	READ_STH
};

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

enum			e_rbtclr
{
	RED,
	BLACK
};

/*
**	Used to determine what to do with the content that is the same
*/

enum			e_rbt_replace
{
	RBT_ADD,
	RBT_REPLACE
};

typedef struct	s_rbtree
{
	int					id;
	void				*content;
	size_t				content_size;
	enum e_rbtclr		colour;
	struct s_rbtree		*parent;
	struct s_rbtree		*left;
	struct s_rbtree		*right;
}				t_rbt;

typedef struct	s_obj
{
	void	*data;
	size_t	size;
}				t_obj;

typedef struct	s_queue
{
	t_list	*data;
	t_list	*last;
}				t_queue;

typedef struct	s_hash_item
{
	void	*key;
	size_t	ksize;
	void	*value;
	size_t	vsize;
}				t_hash_item;

# define DELETED_HI (void *)1
# define BASE_ASCII 269
# define ALTBASE_ASCII 271

typedef struct	s_hash_table
{
	uint32_t	size;
	uint32_t	count;
	uint32_t	base;
	uint32_t	altbase;
	t_hash_item	**items;
}				t_htab;

typedef struct	s_hash_collision_info
{
	uint32_t	base;
	uint32_t	altbase;
	uint32_t	attempt;
}				t_hash_collision_info;

typedef t_htab	t_graph;

# define VARR_BUF_SIZE 1024

typedef struct	s_varr
{
	t_list		*buf;
	size_t		elem_size;
	size_t		size;
}				t_varr;

/*
**	'INFINITE' ARRAYS ==========================================================
*/

void			ft_varrappend(t_varr *varr, void const *content);
void			ft_varrcpy(void *dest, t_varr *varr);
void			ft_varrdel(t_varr **varr);
void			*ft_varrget(t_varr *varr, size_t idx);
t_varr			*ft_varrnew(size_t elem_size);
void			ft_varrset(t_varr *varr, size_t idx, void *content);

/*
**	HASH TABLES ================================================================
*/

/*
**	Hinew and hilnew differ in that hinew copies the data held at value's
**	address, while hilnew simply copies the pointer
**
**	Similarly, hidel frees key, value and item, while hildel does not free value
*/

uint32_t		ft_hash(void const *key, size_t ksize,
		uint32_t base, uint32_t tabsize);
uint32_t		ft_hashget(void const *key, size_t ksize,
		t_hash_collision_info *info, uint32_t tabsize);
void			ft_hidel(t_hash_item **item);
void			ft_hildel(t_hash_item **item);
t_hash_item		*ft_hinew(void const *key, size_t ksize,
		void const *value, size_t vsize);
t_hash_item		*ft_hilnew(void const *key, size_t ksize,
		void *value, size_t vsize);
int64_t			ft_htadd(t_htab *table, t_hash_item *item);
void			ft_htdel(t_htab **table, void (*delfunc)(t_hash_item **));
void			ft_htdel_item(t_htab *table, void *key, size_t ksize,
		void (*delfunc)(t_hash_item **item));
int64_t			ft_htgetid(t_htab *table,
		void const *key, size_t size);
void			*ft_htget(t_htab *table,
		void const *key, size_t ksize, size_t *vsize);
int				ft_htisempty(t_htab *table);
t_htab			*ft_htnew(uint32_t size, uint32_t base, uint32_t altbase);
int				ft_htset(t_htab *tab, void *value, size_t size);

/*
**	GRAPHS =====================================================================
*/

int64_t			ft_graphadd(t_graph *g, void const *key, size_t ksize);
void			ft_graphdel(t_graph **g);
int64_t			ft_graphget(t_graph *g, void const *key, size_t ksize);
t_graph			*ft_graphnew(uint32_t size);

/*
**	The functions below only implement basic unweighted edges
**	More functionality can be added in projects if necessary
*/

void			ft_graphadd_edge(t_graph *g, t_obj *a, t_obj *b);
void			ft_graphadd_uedge(t_graph *g, t_obj *a, t_obj *b);
void			ft_graphadd_edge_id(t_graph *g, uint32_t source, uint32_t sink);
void			ft_graphadd_uedge_id(t_graph *g, uint32_t a, uint32_t b);
int				ft_graphhas_edge(t_graph *g, uint32_t source, uint32_t sink);

/*
**	QUEUES =====================================================================
*/

void			ft_qdel(t_queue **q);
int				ft_qisempty(t_queue *q);
t_queue			*ft_qnew(t_list *elem);
t_list			*ft_qpop(t_queue *q);
void			ft_qpush(t_queue *q, t_list *elem);

/*
**	LINKED LISTS ===============================================================
*/

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddsorted(t_list **alst, t_list *newlst,
		int (*cmp)(void *, void *));
t_list			*ft_lstappend(t_list *alst, t_list *new);
t_list			*ft_lstcpy(t_list *lst);
void			ft_lstdel(t_list **alst, void (*del)(void **, size_t *));
void			ft_lstdelone(t_list **alst, void (*del)(void **, size_t *));
void			ft_lstdelif(t_list **alst, int (*f)(t_list *, void *),
		void *data, void (*del)(void **, size_t *));
t_list			*ft_lstfind(t_list *lst, int (*f)(t_list *, void *),
		void *data);
t_list			*ft_lstfromchr(char const *content, size_t len);
void			ft_lstiter(t_list *lst, void (*f)(t_list *));
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
t_list			*ft_lstnew(void const *content, size_t size);
t_list			*ft_lstnewlink(void *content, size_t size);
t_list			*ft_lstnewmem(size_t size);
char			*ft_lsttostr(t_list *lst, char sep);
char			**ft_lsttotab(t_list *lst);

/*
**	MEMORY OPERATIONS ==========================================================
*/

void			ft_bzero(void *s, size_t n);
void			ft_delcontent(void **content, size_t *size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_memdel(void **ap);
void			*ft_memdup(const void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
**	OUTPUT FUNCTIONS ===========================================================
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnchar(char c, unsigned int n);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putlst(t_list *lst);
void			ft_putmem(const void *data, size_t size, uint8_t octs_per_line);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr_utf_fd(char const *s, int fd);
void			ft_putstr_utf_fd_safe(char const *s, int fd);
void			ft_puttab(const char **tab);
int				ft_pututf_fd(char const *c, int fd);
int				ft_pututf_fd_safe(char const *c, int fd);

/*
**	RED BLACK TREES ============================================================
*/

enum e_rbtclr	ft_rbtcolour(t_rbt *node);
void			ft_rbtdel(t_rbt **root, void (*del)(void **, size_t *));
void			ft_rbtdelone(t_rbt *node, void (*del)(void **, size_t *));
t_rbt			*ft_rbtfindbyid(t_rbt *root, int id);
void			ft_rbtfix(t_rbt **root_node, t_rbt *new);
t_rbt			*ft_rbtfromchr(int id, char const *content, size_t len);
unsigned int	ft_rbtgetbheight(t_rbt *root);
t_rbt			*ft_rbtgetroot(t_rbt *node);
t_rbt			*ft_rbtgetsibling(t_rbt *node);
void			ft_rbtinsertbyid(t_rbt **root_node, t_rbt *new);
void			ft_rbtinsertbycmp(t_rbt **root_node, t_rbt *new,
		int (*cmp)(void *, void *), enum e_rbt_replace replace);
int				ft_rbtisleft(t_rbt *node);
int				ft_rbtisvalid(t_rbt *root);
t_rbt			*ft_rbtmin(t_rbt *root);
t_rbt			*ft_rbtnew(int id, void const *content, size_t size);
void			ft_rbtrm(t_rbt **root, t_rbt *to_delete,
		void (*del)(void **, size_t *));
void			ft_rbtrmbyid(t_rbt **root, int id,
		void (*del)(void **, size_t *));
t_rbt			*ft_rbtrotate(t_rbt *root, char dir);
void			ft_rbtswapcolours(t_rbt *a, t_rbt *b);
void			ft_rbtupdatecontent(t_rbt *node, void *content, size_t size);
void			ft_rbtupdatenode(t_rbt *old, t_rbt *new);
void			ft_rbtupdatestr(t_rbt *node, char *s, size_t len);

/*
**	STRING OPERATIONS ==========================================================
*/

char			*ft_itoa(int n);
char			*ft_itoa_pad(int n, int min_len);
char			*ft_stpcpy(char *dst, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
unsigned int	ft_strcount(char *s, char c);
void			ft_strdel(char **s);
char			*ft_strdup(const char *s);
int				ft_strequ(char const *s1, char const *s2);
long			ft_strfind(const char *s, int c);
long			ft_strfindif(const char *s, int (*f)(char));
long			ft_strfindnot(const char *s, int c);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);
t_list			*ft_strlsplit(char const *s, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_strtoupper(char *s);
char			*ft_strtrim(char const *s);
int				ft_u32to8(wchar_t in, char *out);
int				ft_uchar_len(char const *c);
char			*ft_wstrdup(wchar_t *s);

/*
**	MISCELLANEOUS ==============================================================
*/

int				ft_atoi(const char *str);
int				ft_ilogb(double x);
int				ft_ilogbl(long double x);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isprime(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_gnl(const int fd, char **line);
long			ft_ltoi(const char *str);
uint32_t		ft_nextprime(int c);
void			ft_tabdel(char **tab);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
