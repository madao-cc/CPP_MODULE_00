NAME = phonebook

SRCS = Contact.cpp \
	PhoneBook.cpp \
	main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@rm  $(OBJS)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re


