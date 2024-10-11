TARGET_EXEC := libft.a

SRCS := ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_strlen.c ./ft_tolower.c ./ft_toupper.c ./ft_bzero.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_atoi.c ./ft_strdup.c ./ft_memset.c ./ft_memmove.c ./ft_memcpy.c ./ft_calloc.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_strmapi.c ./ft_striteri.c ./ft_itoa.c ./ft_split.c

OBJS := $(SRCS:%.c=%.o)

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	ar -rcs $(TARGET_EXEC) $(OBJS)

so:
	cc -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean all

re: fclean all

