GREEN = \033[3;32m
YELLOW     = \033[3;33m
MAGENTA    = \033[3;35m
CYAN    = \033[3;36m
NC         = \033[0m


SRC= main.c untils.c parsing.c philo_init.c  monitor.c 
NAME = philo

CC= cc
CFLAGS= -Wall -Wextra -Werror -g 


SRC_DIR := src
OBJ_DIR := obj

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_SRC = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_PATH))

all: $(NAME)
	@echo "$(GREEN)Build complete.$(NC)"

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)
	@echo "$(YELLOW)Building $(NAME)...$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_SRC) $(OBJ_DIR)
	@echo "$(CYAN)Clean is done.$(NC)"


fclean: clean
	@rm -f $(OBJ_SRC) 
	@rm -rf $(NAME)
	@echo "$(CYAN)fClean is done.$(NC)"

re: fclean all

.PHONY: all clean fclean re