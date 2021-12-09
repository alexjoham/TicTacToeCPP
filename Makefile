CPP = g++

tictactoe: tictactoe.cpp
	@echo "Compiling and creating tictactoe"
	${CPP} -o tictactoe tictactoe.cpp
