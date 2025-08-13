# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:32:43 by bamarell          #+#    #+#              #
#    Updated: 2025/07/22 12:59:23 by rzvir            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
INCL := ./include

CFLAGS := -Wall -Wextra -Werror -g
CFLAGS += $(addprefix -I,$(INCL))

SRC_PATH ?= ./src/

-include ./src/io/ft_printf/makefile.mk
-include ./src/io/get_next_line/makefile.mk

SRC += io/ft_putchar_fd.c\
	io/ft_putchar.c\
	io/ft_putendl_fd.c\
	io/ft_putnbr_fd.c\
	io/ft_putpad.c\
	io/ft_putstr_fd.c

SRC += ctype/ft_isalnum.c\
	ctype/ft_isalpha.c\
	ctype/ft_isascii.c\
	ctype/ft_isdigit.c\
	ctype/ft_isprint.c\
	ctype/ft_isspace.c\
	ctype/ft_tolower.c\
	ctype/ft_toupper.c\
	ctype/ft_isupper.c\
	ctype/ft_islower.c

SRC += string/ft_bzero.c\
	string/ft_endswith.c\
	string/ft_memchr.c\
	string/ft_memcmp.c\
	string/ft_memcpy.c\
	string/ft_memmove.c\
	string/ft_memrchr.c\
	string/ft_memset.c\
	string/ft_split.c\
	string/ft_startswith.c\
	string/ft_strchr.c\
	string/ft_strchroc.c\
	string/ft_strcmp.c\
	string/ft_strdup.c\
	string/ft_striteri.c\
	string/ft_strjoin.c\
	string/ft_strjoin_s.c\
	string/ft_strlcat.c\
	string/ft_strlcpy.c\
	string/ft_strlen.c\
	string/ft_strmapi.c\
	string/ft_strncmp.c\
	string/ft_strnstr.c\
	string/ft_strrchr.c\
	string/ft_strtrim.c\
	string/ft_substr.c\
	string/ft_isdigits.c

SRC += stdlib/ft_atoi.c\
	stdlib/ft_atol.c\
	stdlib/ft_atoll.c\
	stdlib/ft_strtol.c\
	stdlib/ft_itoa.c\
	stdlib/ft_ltoa_base.c\
	stdlib/ft_ultoa_base.c\
	stdlib/ft_utoa_base.c

SRC += math/ft_abs.c\
	math/ft_fabs.c\
	math/ft_fabsf.c\
	math/ft_fmax.c\
	math/ft_fmaxf.c\
	math/ft_fminf.c\
	math/ft_labs.c\
	math/ft_llabs.c\
	math/ft_max.c\
	math/ft_min.c\
	math/ft_vec2.c\
	math/ft_vec3.c\
	math/ft_vec4.c\
	math/ft_pow.c\
	math/ft_powf.c\
	math/ft_powl.c

SRC += malloc/ft_calloc.c\
		malloc/ft_realloc.c\
		malloc/ft_free2d.c

SRC += dfs/dfs.c

SRC += lst/ft_lstadd_back_bonus.c\
	lst/ft_lstadd_front_bonus.c\
	lst/ft_lstclear_bonus.c\
	lst/ft_lstdelone_bonus.c\
	lst/ft_lstiter_bonus.c\
	lst/ft_lstmap_bonus.c\
	lst/ft_lstnew_bonus.c\
	lst/ft_lstpop_back_bonus.c\
	lst/ft_lstpop_front_bonus.c\
	lst/ft_lstsize_bonus.c\
	lst/ft_lstlast_bonus.c

OBJ = $(addprefix $(SRC_PATH),$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -rcs $(NAME) $(OBJ)

test: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS += -g -fsanitize=address
debug: CFLAGS += -D DEBUG
debug: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean: OBJ += $(OBJ_BONUS)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
