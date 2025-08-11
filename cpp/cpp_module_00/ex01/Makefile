NAME := my_awesome_phone_book

SOURCES := main.cpp Contact.cpp PhoneBook.cpp UI.cpp
OBJECTS := $(SOURCES:.cpp=.o)

CPPFLAGS := -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
