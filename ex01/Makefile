NAME		= main
CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
SRCS		:= Main.cpp Serializer.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX)  $(SRCS) $(CXXFLAGS) -o $(NAME)

clean:
	
fclean:	clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re