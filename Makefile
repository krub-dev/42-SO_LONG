# Program
NAME = so_long

# FLAGS
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address
MLX_FLAGS = -ldl -lglfw -lm -lpthread

# Colours 
RESET 	= \033[0m
RED 	= \033[0;31m
BRED 	= \033[1;31m
GREEN 	= \033[0;32m
BGREEN 	= \033[1;32m
PURPLE 	= \033[0;35m
BPURPLE	= \033[1;35m
BLUE 	= \033[0;34m
BBLUE 	= \033[1;34m
CYAN 	= \033[0;36m
BCYAN 	= \033[1;36m
WHITE 	= \033[0;97m
BWHITE 	= \033[1;97m
YELLOW 	= \033[0;33m
BYELLOW = \033[1;33m

# Sources
SRCS = SRC/so_long.c SRC/level.c SRC/check_level.c SRC/check_path.c SRC/game.c SRC/game_utils.c SRC/displayEnv.c SRC/displayPlayer.c SRC/displayCollectibles.c SRC/displayExit.c SRC/playerController.c SRC/interactions.c SRC/error_exit_free.c 

# Objects
OBJS = $(SRCS:.c=.o)

# Headers
HD = so_long.h
HDLBFT = ./LIBFT/libft.h
HDPF = ./LIBFT/ft_printf.h
HDGNL = ./LIBFT/get_next_line.h
HDMLX = ./MLX42/include/MLX42/MLX42.h

# Libs
LLibft = ./LIBFT/libft.a
LMLX = ./MLX42/build/libmlx42.a

# Rules

# Target default (when you do make)
all: libft MLX42 $(LMLX) $(NAME)

# Create the exec and compile 	
$(NAME): $(SRCS) $(OBJS) $(LLibft)
	@echo "\n$(BGREEN)| Compiled >>> [SO_LONG] | $(RESET)\n"
	cc $(CFLAGS) $(SRCS) $(LMLX) $(LLibft) $(MLX_FLAGS) -o $(NAME)

# Take .c, generate .o
%.o: %.c $(HD) $(HDLBFT) $(HDPF) $(HDGNL) Makefile
	cc $(CFLAGS) -c $< -o $@

####################################################################

# Makfile LIBFT+PRINTF+GNL
libft:
	@cd ./LIBFT && make

####################################################################

# MLX42 - CODAM
$(LMLX):
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4
	@echo "\n$(BPURPLE)| Compiled >>> [MLX42] | $(RESET)\n"

MLX42: ./MLX42
	git clone https://github.com/codam-coding-college/MLX42.git
	@echo "\n$(BPURPLE)| REPO CLONED >>> [MLX42] | $(RESET)\n"

####################################################################

# Clean .o files
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C ./LIBFT clean

# Make clean, delete binary (executable)
fclean: clean
	@rm -f $(NAME)
	@echo "$(BRED)| Deleted >>> [SO_LONG] | $(RESET)\n"
	@$(MAKE) -C ./LIBFT fclean
	@rm -f $(LMLX)
	@echo "$(BRED)| Deleted >>> [MLX42] | $(RESET)\n"

# Fclean and make again
re: fclean all
	@echo "$(BWHITE)| Redone >>> [SO_LONG][MLX42][LIBFT][GET_NEXT_LINE][PRINTF] | $(RESET)\n"
	
# Always execute this rules, good practice
.PHONY: all clean fclean re libft
