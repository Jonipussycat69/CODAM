NAME		=	so_long

#	colours
PINK 			= \033[35m
BLUE			= \033[34;1m
GREEN			= \033[32;1m
CORAL			= \033[38;2;255;127;80m
BOLD			= \033[1m
ITALIC			= \033[3m
UNDER 			= \033[4m
RESET			= \033[0m

#	flags
CFLAGS		=	-Wall -Wextra
CFLAGS		+=	-Werror
#	CFLAGS	+=	-g -fsanitize=address
RM			=	rm -rf

#	libaries
EXTERN_LIBS	=	./extern_libraries
MLX42_PATH	=	$(EXTERN_LIBS)/MLX42
LIB_PATH	=	$(EXTERN_LIBS)/libft/


#	MLX
HEADERS		=	-Iinclude -lglfw -L "/usr/local/Cellar/glfw/3.4/lib/"
MLXLIB		=	$(MLX42_PATH)/build/libmlx42.a

#	directory creation
MKDIR_P		=	mkdir -p

MISC		=	*.out							\
				.DS_Store						\
				*.dSYM/

SRC			=	main.c							\
				map_parsing.c					\
				map_checker.c					\
				map_solve_check.c				\
				textures.c						\
				keyhook.c						\
				movement.c						\
				items_and_exit.c				\
				so_long_utils.c

BSRC		=	main_bonus.c					\
				map_parsing_bonus.c				\
				map_checker_bonus.c				\
				map_solve_check_bonus.c			\
				textures_bonus.c				\
				keyhook_bonus.c					\
				movement_bonus.c				\
				movement_smooth_walking_bonus.c	\
				collision_checks_bonus.c		\
				so_long_utils_bonus.c			\
				rand_num_generator_bonus.c		\
				foes_movement_bonus.c			\
				initialize_bonus.c

LIBFT		=	ft_strlen.c 					\
				ft_memmove.c 					\
				ft_memcpy.c 					\
				ft_strlcpy.c 					\
				ft_strlcat.c 					\
				ft_isalpha.c 					\
				ft_isdigit.c 					\
				ft_isalnum.c 					\
				ft_isascii.c 					\
				ft_isprint.c 					\
				ft_memset.c 					\
				ft_bzero.c 						\
				ft_toupper.c 					\
				ft_tolower.c 					\
				ft_strchr.c 					\
				ft_strrchr.c 					\
				ft_strncmp.c 					\
				ft_memchr.c 					\
				ft_memcmp.c 					\
				ft_strnstr.c 					\
				ft_atoi.c 						\
				ft_calloc.c 					\
				ft_strdup.c 					\
				ft_substr.c 					\
				ft_strjoin.c 					\
				ft_strjoin_free.c 				\
				ft_strtrim.c 					\
				ft_split.c 						\
				ft_itoa.c 						\
				ft_strmapi.c 					\
				ft_striteri.c 					\
				ft_putchar_fd.c 				\
				ft_putstr_fd.c 					\
				ft_putendl_fd.c 				\
				ft_putnbr_fd.c 					\
				ft_lstnew.c 					\
				ft_lstadd_front.c 				\
				ft_lstsize.c 					\
				ft_lstlast.c 					\
				ft_lstadd_back.c 				\
				ft_lstdelone.c 					\
				ft_lstclear.c 					\
				ft_lstiter.c 					\
				ft_lstmap.c 					\
				get_next_line.c 				\
				ft_cpy.c 						\
				ft_free_str.c 					\
				ft_free_ptr.c 					\
				free_2d_array.c		 			\
				ft_printf/ft_printf.c 			\
				ft_printf/ft_printf_count.c		\
				ft_printf/ft_printf_utils.c		\
				ft_printf/ft_bonus_flags.c		\
				ft_printf/ft_bonus_sort_spec.c	\
				ft_printf/ft_bonus_char.c		\
				ft_printf/ft_bonus_str.c		\
				ft_printf/ft_bonus_str_count.c	\
				ft_printf/ft_bonus_int.c		\
				ft_printf/ft_bonus_unsigned.c	\
				sign.c							\
				safe_sign.c

#	obj_folder
OBJ_DIR		=	objects

#	mandatory
LONG_DIR	=	source
LONG_OBJ	= 	$(patsubst $(LONG_DIR)/%.c, $(OBJ_DIR)/%.o, $(addprefix $(LONG_DIR)/, $(SRC)))
LIBOBJ		=	$(patsubst $(LIB_PATH)%.c, $(OBJ_DIR)/%.o, $(addprefix $(LIB_PATH), $(subst ft_printf/,,$(LIBFT))))
OBJ			= 	$(LONG_OBJ) $(LIBOBJ)

#	bonus
LONG_BDIR	=	bonus
LONG_BOBJ	=	$(patsubst $(LONG_BDIR)/%.c, $(OBJ_DIR)/%.o, $(addprefix $(LONG_BDIR)/, $(BSRC)))
BOBJ		= 	$(LONG_BOBJ) $(LIBOBJ)

all:	objects_mkdir $(NAME) 

$(MLXLIB):
	@cd $(MLX42_PATH) && cmake -B build && cmake --build build -j4
	@echo "$(PINK) libmlx_works $(RESET)"

$(OBJ_DIR)/%.o: $(LONG_DIR)/%.c
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LONG_BDIR)/%.c
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_PATH)%.c
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_PATH)ft_printf/%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLXLIB)
	cc $(CFLAGS) $(OBJ) $(MLXLIB) $(HEADERS) -lm -o $(NAME)
	@echo "$(PINK) compile $(RESET)"

bonus: objects_mkdir $(BOBJ) $(MLXLIB)
	cc $(CFLAGS) $(BOBJ) $(MLXLIB) $(HEADERS) -lm -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR) $(MISC)
	@$(RM) $(MLX42_PATH)/build
	@echo "$(PINK) clean $(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(PINK) fclean $(RESET)"

re:		fclean all

bre:	fclean bonus

objects_mkdir:
	@$(MKDIR_P) $(OBJ_DIR)

map1:	all
	./so_long "./maps/basic/1.ber"
map2:	all
	./so_long "./maps/basic/2.ber"
map3:	all
	./so_long "./maps/basic/3.ber"
map4:	all
	./so_long "./maps/basic/4.ber"
map5:	all
	./so_long "./maps/basic/5.ber"
map6:	all
	./so_long "./maps/basic/6.ber"
map7:	all
	./so_long "./maps/basic/7.ber"
mapall:	all
	./so_long "./maps/basic/1.ber" && ./so_long "./maps/basic/2.ber" && ./so_long "./maps/basic/3.ber" && ./so_long "./maps/basic/4.ber" && ./so_long "./maps/basic/5.ber"

test1:	all
	./so_long "./maps/test/1.ber"
test2:	all
	./so_long "./maps/test/2.ber"
test3:	all
	./so_long "./maps/test/3.ber"
test4:	all
	./so_long "./maps/test/4.ber"
test5:	all
	./so_long "./maps/test/5.ber"
test6:	all
	./so_long "./maps/test/6.ber"
test7:	all
	./so_long "./maps/test/NonExistent"

b1:	bonus
	./so_long "./maps/bonus/b1.ber"

.PHONY:	all bonus clean fclean re bre objects_mkdir