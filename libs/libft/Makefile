
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

FILES =	ft_memset.c ft_bzero.c \
					ft_memcpy.c ft_memmove.c \
					ft_memchr.c ft_memcmp.c \
					ft_strlen.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c \
					ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c \
					ft_strchr.c ft_strrchr.c \
					ft_strncmp.c ft_strlcpy.c \
					ft_strlcat.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c \
					ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_split.c \
					ft_itoa.c ft_putchar_fd.c \
					ft_strtrim.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_putstr_fd.c \
					ft_striteri.c ft_strmapi.c get_next_line.c get_next_line_utils.c\

BFILES = $(FILES) ft_lstnew_bonus.c ft_lstiter_bonus.c \
					ft_lstsize_bonus.c ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
					ft_lstdelone_bonus.c ft_lstclear_bonus.c\
					ft_lstmap_bonus.c \

OBJS = $(FILES:.c=.o)

B_OBJS = $(BFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(B_OBJS)
	ar -rc $(NAME) $(B_OBJS)

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: all fclean

