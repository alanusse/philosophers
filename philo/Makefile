# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 13:05:54 by aglanuss          #+#    #+#              #
#    Updated: 2024/05/16 13:40:22 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = Agustín Lanusse (aglanuss)

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

### FILES ###

UTILS = $(wildcard utils/*.c)

INCLUDES = $(wildcard includes/*.h)

SRCS = $(wildcard src/*.c) $(UTILS)

OBJS = $(SRCS:.c=.o)

### COLORS ###

BLUE_COLOR   = \033[0;36m
RED_COLOR  = \033[0;33m
GREEN_COLOR    = \033[0;32m
RESET_COLOR = \033[0m

### TARGETS ###

all:
	@$(MAKE) header
	@$(MAKE) $(NAME)

header:
	@printf "%b" "$(GREEN_COLOR)"
	@echo "  __  __       _         __ _ _      "
	@echo " |  \/  |     | |       / _(_) |     "
	@echo " | \  / | __ _| | _____| |_ _| | ___ "
	@echo " | |\/| |/ _\` | |/ / _ \  _| | |/ _ \\"
	@echo " | |  | | (_| |   <  __/ | | | |  __/"
	@echo " |_|  |_|\__,_|_|\_\___|_| |_|_|\___|"
	@echo
	@printf "%b" "$(BLUE_COLOR)Name:	$(RED_COLOR)$(NAME)\n"
	@printf "%b" "$(BLUE_COLOR)Author:	$(RED_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(BLUE_COLOR)CC: 	$(RED_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(BLUE_COLOR)Flags: 	$(RED_COLOR)$(CFLAGS)\n\033[m"
	@echo

$(NAME): $(OBJS)
	@echo "\n\n[$(NAME)] $(GREEN_COLOR)object files were created$(RESET_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "[$(NAME)] $(GREEN_COLOR)$(NAME) executable was created$(RESET_COLOR)"

%.o: %.c $(INCLUDES) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN_COLOR).$(RESET_COLOR)\c"

clean:
	@$(RM) $(OBJS)
	@echo "[$(NAME)] $(GREEN_COLOR)removed object files$(RESET_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "[$(NAME)] $(GREEN_COLOR)$(NAME) executable was removed$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re header