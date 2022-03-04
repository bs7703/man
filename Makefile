CC=g++
FLAGS=-std=c++98 -Wall -Werror -Wextra
SRCS=tests.cpp Account.cpp
OBJS=$(SRCS:.cpp=.o)
NAME=Account

$(NAME): $(OBJS)
	$(CC) -o $@ $(FLAGS) $^

%.o: %.cpp
	$(CC) -c $^

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re:
	make fclean
	make
