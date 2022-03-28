CXX			= c++

CXXFLAGS 	=  -g -Wall -Wextra -Werror -std=c++98

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[0;33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m 

all: start_vector start_stack start_set start_map

VECTOR		= vector_test

$(VECTOR):
	@($(CXX) $(CXXFLAGS) ./tests/t_vector.cpp -o $(VECTOR))

start_vector: $(VECTOR)
			@./$(VECTOR)
			@rm $(VECTOR)
			@rm -rf ./vector_test.dSYM

STACK		= stack_test

$(STACK):
	@($(CXX) $(CXXFLAGS) ./tests/t_stack.cpp -o $(STACK))

start_stack: $(STACK)
			@./$(STACK)
			@rm $(STACK)
			@rm -rf ./stack_test.dSYM

SET		= set_test

CPP_SET = ./tests/t_set.cpp

$(SET):
	@($(CXX) $(CXXFLAGS) $(CPP_SET) -o $(SET))

start_set: $(SET)
			@./$(SET)
			@rm $(SET)
			@rm -rf ./set_test.dSYM

MAP		= map_test

CPP_MAP = ./tests/t_map.cpp

$(MAP):
	@($(CXX) $(CXXFLAGS) $(CPP_MAP) -o $(MAP))

start_map: $(MAP)
			@./$(MAP)
			@rm $(MAP)
			@rm -rf ./map_test.dSYM