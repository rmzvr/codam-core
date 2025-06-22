NAME := minishell

INCLUDES_PATH =	includes/
SOURCES_PATH =	sources/

BUILD_PATH =	build/
LIBS_PATH =		libs/

LIBFT_PATH =	$(LIBS_PATH)libft/
LIBFT =			$(LIBFT_PATH)libft.a

SRCS :=		\
				executable/prompt/prompt.c \
				executable/prompt/prompt_utils.c \
				executable/prompt/prompt_helpers.c \
				executable/prompt/additional_utils.c \
				executable/prompt/utils.c \
				executable/builtins/builtin.c \
				executable/builtins/cd/cd.c \
				executable/builtins/cd/cd_utils.c \
				executable/builtins/echo/echo.c \
				executable/builtins/env/env.c \
				executable/builtins/env_utils/env_utils.c \
				executable/builtins/env_utils/getenv.c \
				executable/builtins/env_utils/putenv.c \
				executable/builtins/env_utils/putenv_utils.c \
				executable/main.c \
				executable/builtins/execve/executable_finder.c \
				executable/builtins/execve/executable_finder_utils.c \
				executable/builtins/execve/executable_launcher.c \
				executable/builtins/execve/executable_launcher_utils.c \
				executable/builtins/exit/exit.c \
				executable/builtins/export/export.c \
				executable/pipe/pipe.c \
				executable/builtins//pwd/pwd.c \
				executable/readline/readline.c \
				executable/readline/readline_utils.c \
				executable/readline/tree_creator.c \
				executable/readline/home_path_utils.c \
				executable/redirect/redirect.c \
				executable/redirect/redirect_utils.c \
				executable/signals/signal_handler.c \
				executable/signals/wait_children.c \
				executable/builtins/unset/unset.c \
				executable/utils/char_array_utils.c \
				executable/utils/error_handlers.c \
				executable/utils/fd_handler.c \
				executable/utils/file_error_handlers.c \
				executable/utils/free_parser_utils.c \
				executable/utils/free_utils.c \
				executable/utils/memory_error_handlers.c \
				executable/utils/syntax_error_handlers.c \
				executable/utils/utils.c \
				executable/utils/validators.c \
				executable/utils/variable_helpers.c \
				parser/utils/token_utils.c \
				parser/utils/buffer_utils.c \
				parser/utils/token_operations.c \
				parser/helpers/char_helpers.c \
				parser/helpers/token_helpers.c \
				parser/syntax_tree/option_handler.c \
				parser/syntax_tree/command_handler.c \
				parser/syntax_tree/pipeline_handler.c \
				parser/syntax_tree/syntax_tree_handler.c \
				parser/tokenizer/initializer.c \
				parser/tokenizer/start_state_utils.c \
				parser/tokenizer/accept_state_utils.c \
				parser/tokenizer/string_state_utils.c \
				parser/tokenizer/delimiter_state_utils.c \
				parser/tokenizer/intermediate_state_utils.c \
				parser/tokenizer/environmental_variable_utils.c \
				parser/heredoc/utils.c \
				parser/heredoc/file_utils.c \
				parser/heredoc/token_utils.c \
				parser/heredoc/buffer_utils.c \
				parser/heredoc/signal_handler.c \
				parser/heredoc/heredoc_executor.c \
				parser/heredoc/heredoc_evaluator.c \
				parser/heredoc/heredoc_expansion.c \
				parser/heredoc/delimiter_handler.c \
				parser/evaluator/evaluator.c \
				parser/evaluator/buffer_utils.c \
				parser/evaluator/quote_evaluator.c \
				parser/evaluator/quote_evaluator_utils.c \
				parser/evaluator/evaluator_helpers.c \
				parser/evaluator/token_concatenator.c \
				parser/evaluator/exit_code_evaluator.c \
				parser/evaluator/redirection_helpers.c \
				parser/evaluator/syntax_error_handler.c \
				parser/evaluator/redirection_evaluator.c \
				parser/evaluator/environment_variable_evaluator.c \
				parser/scanner/scanner.c \
				parser/scanner/quote_handlers.c \
				parser/scanner/symbol_handlers.c \

OBJS :=			$(SRCS:.c=.o)

SOURCES = 		$(addprefix $(SOURCES_PATH), $(SRCS))
OBJECTS = 		$(addprefix $(BUILD_PATH), $(OBJS))

CC :=			cc

CFLAGS :=		-Wall -Wextra -Werror \
				-I$(INCLUDES_PATH) -I$(LIBFT_PATH)

LDFLAGS :=		-lreadline

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBFT) -o $(NAME)

$(BUILD_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

clean:
	rm -rf $(BUILD_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@mkdir $(BUILD_PATH)

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
