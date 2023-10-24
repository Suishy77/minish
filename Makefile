NAME			=	minishell

LIBFT			=	libft.a

DIR_SRCS		=	srcs
DIR_OBJS		=	objs

SRCS_NAMES		=	lexer/expand.c \
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
					utils/utils3.c	\
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
					exec/redir2.c

OBJS_NAMES		=	$(SRCS_NAMES:.c=.o)

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Iincludes/ -Ilibft/includes/
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[33m----Compiling----"
	@make -C libft
	@mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME) -lreadline
	@echo "\033[32mMinishell Compiled!\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p $(dir $(OBJS))

clean:
	make clean -C libft
	$(RM) $(DIR_OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

party:
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"


.PHONY: all clean fclean re party
