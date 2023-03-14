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

NAME = ex02
ASAN = ex02_asan

SRCS = src/Account.cpp  src/tests.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++03
ASANFLAGS = -g -fsanitize=address

all: $(NAME)

asan: $(ASAN)

test: $(NAME)
	@./$(NAME) > test.log

$(ASAN): $(OBJS)
	$(CXX) $(ASANFLAGS) $(CXXFLAGS) $(OBJS) -o $(ASAN)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm $(OBJS)
	@rm test.log

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(ASAN)

re:
	@$(MAKE) fclean
	@$(MAKE) all
