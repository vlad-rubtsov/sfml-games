CC=g++
AR=ar
#INC=-I../../
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
DEFINES=

FLAGS=-std=c++17 -g

TARGET=first

OBJECTS=main.o Game.o Window.o ArkanoidGame.o



all: ${TARGET}

## targets
${TARGET} : ${OBJECTS}
	${CC} ${FLAGS} ${INC} ${DEFINES} ${OBJECTS} ${LIBS} -o ${TARGET}

main.o : main.cpp
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<

%.o : %.cpp %.h
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<
	
## clean all
clean :
	rm -rf ${TARGET} ${OBJECTS}

.PHONY: clean
