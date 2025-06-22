# Colors
YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
CYAN	:= \033[1;36m
RED		:= \033[1;31m
RESET	:= \033[0m


#HEADERS
HEADERS := ft_dprintf.h

#SOURCES
SRCS	:=	ft_dprintf.c \
			ft_dprintf_c.c \
			ft_dprintf_s.c \
			ft_dprintf_d.c \
			ft_dprintf_x.c \
			ft_dprintf_ux.c \
			ft_dprintf_p.c \
			ft_dprintf_u.c \
			ft_dprintf_i.c \
			ft_dprintf_percent.c \
			ft_convert_to_base.c \

#TARGET
NAME := libftdprintf.a

#OBJECTS
OBJS := $(SRCS:%.c=%.o)

#FLAGS
CC		:= cc -c
CFLAGS	:= -Wall -Werror -Wextra
AR		:= ar rcs

#RULES
all : $(NAME)

$(NAME) : $(OBJS)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	@$(AR) $@ $(OBJS)
	@echo -e "$(GREEN)Printf library has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] $< -> $@$(RESET)"
	@$(CC) $(CFLAGS) $< -o $@

clean :
	@echo -e "$(RED)[CLEAN] Removing object files...$(RESET)"
	@rm -f $(OBJS)

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing $(NAME) and debug libraries...$(RESET)"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
