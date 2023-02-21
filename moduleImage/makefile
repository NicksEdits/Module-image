NAME = projet
OBJ_FILES = main.o Pixel.o Image.o

all : ${NAME}

${NAME}: ${OBJ_FILES}
	g++ ${OBJ_FILES} -o ${NAME}

main.o: main.cpp
	g++ -Wall -c main.cpp 

Pixel.o: Pixel.cpp Pixel.hpp
	g++ -Wall -c Pixel.cpp

Image.o: Image.cpp Image.hpp
	g++ -Wall -c Image.cpp
clean:
	rm ${OBJ_FILES}