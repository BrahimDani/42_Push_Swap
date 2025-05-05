NAME            =		push_swap

CC              =       cc

FLAG            =       -g

LIBFT_FILE      =		libft.a

LIBFT_PATH      =       ./libft/

LIBFT_LIB       =       $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

LIBFT_EX        =       $(LIBFT_LIB) $(FLAG)

C_FILE          =       main.c							\
						utils.c							\
						sort.c							\
						sort_utils.c					\
						normalise.c						\
						fill_stack.c					\
						check_param.c					\
						instruction/push.c				\
						instruction/reverse_rotate.c	\
						instruction/rotate.c			\
						instruction/swap.c


SRC_DIR         =       ./src/

INC_DIR         =       ./includes/

SRC 			=		$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			    =		$(SRC:.c=.o)

.c.o:
		$(CC) $(FLAG) -I $(INC_DIR) -I $(LIBFT_PATH) -c $< -o $@

all: $(NAME)

./libft/libft.a:
		@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)...\n"
		@make -sC $(LIBFT_PATH)
		@echo "\033[1;32mLIBFT created\033[0m\n"

$(NAME): ./libft/libft.a $(OBJ)
		@echo "\033[0;33m\nCOMPILING PUSH_SWAP...\n"
		$(CC) $(OBJ) -I $(INC_DIR) -I $(LIBFT_PATH) $(LIBFT_EX) -o $(NAME)
		@echo "\033[1;32m./push_swap created\033[0m\n"

clean:
		@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
		@make clean -sC $(LIBFT_PATH)
		@echo "\033[1;32mDone\n"
		@echo "\033[0;31mDeleting all object...\n"
		@rm -f $(OBJ) $(NAME)
		@echo "\033[1;32mDone\033[0m\n"

fclean: clean
		@echo "\033[0;31mDeleting executable..."
		@rm -f $(NAME)
		@make clean -sC $(LIBFT_PATH)
		@echo "\033[1;32mDone\033[0m\n"

re: fclean all

.PHONY: all clean fclean re