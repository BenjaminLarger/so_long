# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blarger <blarger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 09:17:09 by blarger           #+#    #+#              #
#    Updated: 2024/02/09 16:24:50 by blarger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			:= so_long
HEADER			:= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${FT_PRINTF}
LIBGL			:= -lglfw -L"/Users/blarger/.brew/opt/glfw/lib"
RM 				:= rm -f
LIBMLX_DIR		:= Library/MLX42/
LIBMLX			:= $(LIBMLX_DIR)libmlx42.a
LIBFT_DIR		:= Library/Libft/
LIBFT 			:= $(LIBFT_DIR)libft.a
FT_PRINTF_DIR	:= Library/Ft_printf/
FT_PRINTF 		:= $(FT_PRINTF_DIR)libftprintf.a

CC 				:= cc
CFLAGS 			:= -Wall -Werror -Wextra -Imlx -IInclude
MLX_FLAGS		:= -framework Cocoa -framework OpenGL -framework IOKit


#Colors
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

#Sources
SRC_DIR					= Sources/
OBJ_DIR					= Objects/
SRC_FILES				= 0_main 1_check_input_and_read_map 1_check_input_and_read_map_utils 2_check_map 2_check_map_utils 2_valid_way 3_mlx_features 4_get_visual 5_moves 6_collectible 7_free
SRC						= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 					= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(notdir $(SRC_FILES))))
DEPS					= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS					= $(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))


#Bonus
BONUS_NAME				= so_long_bonus
BONUS_SRC_DIR			= Bonus/Sources/
BONUS_OBJ_DIR			= Bonus/Objects/
BONUS_SRC_FILES			= $(addprefix $(BONUS_SRC_DIR), $(addsuffix _bonus, $(SRC_FILES))) 5_move_enemy_bonus 5_move_enemy_utils_bonus 5_valid_enemy_move_bonus
BONUS_OBJ				= $(addprefix $(BONUS_OBJ_DIR), $(addsuffix .o, $(notdir $(BONUS_SRC_FILES))))

#Rules
all: libft libmlx libpf  ${NAME}

libft:
			@${MAKE} -C ${LIBFT_DIR}
			@echo "$(GREEN)libft compiled!$(DEF_COLOR)"	

libmlx:
			@${MAKE} -C ${LIBMLX_DIR}
			@echo "$(GREEN)MLX42 compiled!$(DEF_COLOR)"	
	
libpf:
			@${MAKE} -C ${FT_PRINTF_DIR}
			@echo "$(GREEN)printf compiled!$(DEF_COLOR)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)
			@echo "${BLUE} ◎ $(BROWN)Compiling bonus  ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
#			@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(FT_PRINTF) $(LIBMLX) -o $(NAME)$(DEF_COLOR)"
			${CC} -o $(NAME) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(OBJ) $(LIBMLX) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(CFLAGS) $(MLX_FLAGS)
			@echo "$(GREEN)$(NAME) ✨ SO_LONG compiled!$(DEF_COLOR)"

bonus: $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(MLX_FLAGS) $(BONUS_OBJ) $(FT_PRINTF) $(LIBMLX) -o $(BONUS_NAME)$(DEF_COLOR)"
	${CC} -o $(BONUS_NAME) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(BONUS_OBJ) $(LIBMLX) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(CFLAGS) $(MLX_FLAGS)
	@echo "$(GREEN)$(BONUS_NAME) ✨ SO_LONG bonus compiled!$(DEF_COLOR)"

clean:
			rm -f $(OBJ)
			rm -f $(BONUS_OBJ)
			make -C $(FT_PRINTF_DIR) clean
			@echo "$(CYAN)ft_printf object cleaned.$(DEF_COLOR)"
			make -C $(LIBFT_DIR) clean
			@echo "$(CYAN)libft object cleaned.$(DEF_COLOR)"
			make -C $(LIBMLX_DIR) clean
			@echo "$(CYAN)minilibx object cleaned.$(DEF_COLOR)"

fclean:
			$(RM) $(NAME)
			@echo "$(CYAN)so_long executable files cleaned!$(DEF_COLOR)"
			$(RM) $(BONUS_NAME)
			@echo "$(CYAN)so_long_bonus executable files cleaned!$(DEF_COLOR)"
			make -C $(FT_PRINTF_DIR) fclean
			@echo "$(CYAN)ft_printf lib cleaned!$(DEF_COLOR)"
			make -C $(LIBFT_DIR) fclean
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"
			make -C $(LIBMLX_DIR) fclean
			@echo "$(CYAN)libmlx42.a lib cleaned!$(DEF_COLOR)"

re: fclean all

.Phony: all clean fclean re