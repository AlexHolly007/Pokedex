CC=g++ -std=c++11 -g
exe=prog

$(exe): create_dex_functions.o option_functions.o output_functions.o driver.cpp
	$(CC) create_dex_functions.o option_functions.o output_functions.o driver.cpp -o $(exe)

create_dex_functions.o: create_dex_functions.cpp pokemon.h
	$(CC) -c create_dex_functions.cpp 

option_functions.o: option_functions.cpp pokemon.h
	$(CC) -c option_functions.cpp

output_functions.o: output_functions.cpp pokemon.h
	$(CC) -c output_functions.cpp

clean: 
	rm -f *.o $(exe)
