NAME= libftprintf.a

SRC_PATH= .
SRC_NAME=	apply_signs.c		fetch_by_sizem.c	ft_putonbr.c\
			save_precision.c	apply_hash.c		apply_width.c\
	   		ft_printf.c			ft_putunbr.c		save_width.c\
			apply_precision.c	build_result.c		ft_putxnbr.c\
			printb.c			set_color.c			apply_quote.c\
			ft_putdnbr.c		save_flags.c		main_original.c\
			ft_putfnbr.c 		ft_putc_and_s.c \
			float_all_bigint_functions.c \
			float_construction_functions.c \
			float_helper_functions_unnecessary.c \
			float_main_functions.c \
			float_mini_dragon4.c

SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB_OBJ_PATH= libft/obj/*.o

LIB_PATH= libft
LIB= libft.a

# ***************************************** #
# Dont tuch thi code under this				#
# exept what I told you so in the comments	#
# ***************************************** #

CC=	gcc
CFLAGES= -Wall -Wextra -Werror
#CFLAGES= -g

LD_FLAGS= -L$(LIB_PATH)
LD_LIBS= -l$(patsubst lib%.a,%, $(LIB))
HDR_FLAGS= -I.


all:$(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ_PATH)
	@ranlib $(NAME)
	@echo "ft_printf: library file is ready ;)" 	########## modify this

$(LIB_PATH)/$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<

clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@echo "ft_printf: object files deleted" 			########## modify this

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@echo "ft_printf: all resources deleted" 			########## modify this

re: fclean all
