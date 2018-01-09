CXX = g++
SRCS = Item.cpp List.cpp main.cpp 
HEADERS = Item.hpp List.hpp 

main: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o main

clean:
	rm main
