CC=g++ -g
exe=prog

$(exe): filepoke.o driver.cpp
	$(CC) filepoke.o driver.cpp -o $(exe)

filepoke.o: filepoke.cpp pokemon.h
	$(CC) -c filepoke.cpp 

clean: 
	rm -f *.o $(exe)
