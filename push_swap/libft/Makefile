NAME := libft.a

PRINTF_DIR := ./ft_printf
PRINTF_NAME   = $(PRINTF_DIR)/libftprintf.a

SOURCES := \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_nbrlen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_bzero.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_calloc.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_split.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	ft_isspace.c \
	ft_isminus.c \
	ft_issign.c \
	ft_atoll.c \
	ft_atof.c \

OBJECTS := $(SOURCES:%.c=%.o)

CC := cc
FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(PRINTF_DIR)
	mv $(PRINTF_NAME) ./$@
	ar -rcs $(NAME) $^

$(PRINTF_NAME):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re