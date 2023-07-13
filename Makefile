NAME = minishell

SRCS =  lexer/expand.c \
        lexer/expand2.c \
		lexer/get_tokens.c \
		lexer/get_tokens2.c \
		lexer/get_tokens3.c \
		lexer/lexer_init.c \
		lexer/lexer.c \
		lexer/split_utils.c \
		lexer/syntax_error.c \
		lexer/syntax_utils.c \
		lexer/treat_prompt.c \
		lexer/treat_prompt2.c \
		lexer/treat_prompt3.c \
        utils/garbage_collector.c \
        utils/signals.c \
        utils/utils.c \
		utils/utils2.c \
        parser/fill_par_cmd.c \
		parser/fill_par_red.c \
		parser/here_doc.c \
		parser/parser_utils.c \
		parser/parser.c \
        builtins/builtins.c \
        builtins/echo.c \
		builtins/exit.c \
		builtins/export_error.c \
		builtins/export_print.c \
		builtins/export.c \
		builtins/unset.c \
        exec/builtin_exec.c \
        exec/builtin_exec2.c \
		exec/error.c \
		exec/exec_utils.c \
		exec/exec.c \
		exec/redir.c \
		exec/redir2.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C libft
	@ar -rcs libft/libft.a
	@cp libft/libft.a libft.a
	@${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME} -lreadline

clean: 
	@make -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} libft.a

re: fclean all

.PHONY: all clean fclean re