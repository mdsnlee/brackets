
NAME = brackets
#interchangeable

SRC = 	main 
#more files in SCR add it here

INC = -I inc

#LDFLAGS = (- library)

VPATH = src
#if make more files add it here

OBJ_DIR = obj
BIN_DIR = bin

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))
DEP = $(OBJ:%.o=%.d) #optional

CC = g++
#can be clang-6.0
#dont need to continue writing this

CFLAGS = -std=c++11 $(INC)
MAKEOPTS = -j4 #optional

all:  $(OBJ_DIR) $(BIN_DIR) $(NAME)


-include $(DEP)

#almost never need to change this
$(OBJ_DIR):
	@printf "\033[32mMaking: Objects\033[0m\n"
	#for color and aesthetics
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@printf "\033[32mCompiling: \033[0m%s\n" $<
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	
#g++ -2td=c++11 main.c -o fillit --> $(CC) $(CFLAGS) $(SRC) -o fillit

$(BIN_DIR):
	@printf "\033[32mMaking: Bin\033[0m\n"
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJ)
	@printf "\033[32mLinking: \033[0m\n" $@
	@$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@ 
	#LDFLAGS goes in line above if libraries aren't empty

clean:
	@printf "\033[33mCleaning: objects...\033[0m\n"
	@re -f $(OBJ_DIR)
	#.o and .d files

fclean: clean #same line
	@printf "\033[33mCleaning: executables...\033[0m\n"
	@rm -f $(BIN_DIR)/$(NAME)
	#excecutables

re: fclean all

test:
	g++ -o brackets src/main.cpp -I inc
	./brackets

.PHONY: all clean fclean re test
#has everything

# \033[] : start color code
# 32    : select color
# m     : end color code