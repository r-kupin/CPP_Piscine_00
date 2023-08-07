#
#   /$$$$$$                             /$$$$$$   /$$$$$$ 
#  /$$__  $$                           /$$$_  $$ /$$$_  $$
# | $$  \__/  /$$$$$$   /$$$$$$       | $$$$\ $$| $$$$\ $$
# | $$       /$$__  $$ /$$__  $$      | $$ $$ $$| $$ $$ $$
# | $$      | $$  \ $$| $$  \ $$      | $$\ $$$$| $$\ $$$$
# | $$    $$| $$  | $$| $$  | $$      | $$ \ $$$| $$ \ $$$
# |  $$$$$$/| $$$$$$$/| $$$$$$$/      |  $$$$$$/|  $$$$$$/
#  \______/ | $$____/ | $$____/        \______/  \______/ 
#           | $$      | $$                                
#           | $$      | $$                                
#           |__/      |__/                                
#

NAME = megaphone

SRCS = src/megaphone.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CC = clang++
FLAGS = -Wall -Wextra -Werror  -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
