NAME = ex03
CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g3

SRC = ./srcs/
INCS_DIR = ./incs

FILES =		$(SRC)main.cpp \
			$(SRC)Bureaucrat.cpp \
			$(SRC)AForm.cpp \
			$(SRC)ShrubberyCreationForm.cpp \
			$(SRC)RobotomyRequestForm.cpp \
			$(SRC)PresidentialPardonForm.cpp \
			$(SRC)Intern.cpp \


OBJ_FILES = $(FILES:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

clean : 
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make all


.PHONY : all clean fclean re