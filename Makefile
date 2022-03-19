CXX			= clang++

CXXFLAGS 	=  -g -Wall -Wextra -Werror -std=c++98

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[0;33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m 

all: start_iterator start_memory start_vector start_stack start_set

ITERATOR 	= iterator_test

$(ITERATOR):
	$(CXX) $(CXXFLAGS) ./tests/t_iterator.cpp -o $(ITERATOR)

start_iterator: $(ITERATOR)
			@./$(ITERATOR) || echo " "
			@rm $(ITERATOR) || echo " "

MEMORY 		= memory_test

$(MEMORY):
	$(CXX) $(CXXFLAGS) ./tests/t_memory.cpp -o $(MEMORY)

start_memory: $(MEMORY)
			@./$(MEMORY) || echo " "
			@rm $(MEMORY) || echo " "

VECTOR		= vector_test

$(VECTOR):
	$(CXX) $(CXXFLAGS) ./tests/t_vector.cpp -o $(VECTOR)

start_vector: $(VECTOR)
			@./$(VECTOR) || echo " "
			@rm $(VECTOR) || echo " "

STACK		= stack_test

$(STACK):
	$(CXX) $(CXXFLAGS) ./tests/t_stack.cpp -o $(STACK)

start_stack: $(STACK)
			@./$(STACK) || echo " "
			@rm $(STACK) || echo " "


SET		= set_test

CPP_SET = ./tests/test_set.cpp

$(SET):
	$(CXX) $(CXXFLAGS) $(CPP_SET) -o $(SET)

start_set: $(SET)
			@./$(SET) || echo " "
			@rm $(SET) || echo " "