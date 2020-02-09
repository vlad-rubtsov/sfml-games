CC=g++
AR=ar
#INC=-I../../
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
#DEFINES=-DSPARK_UNICODE -DPLATFORM_LINUX
#DEFINES=-DPLATFORM_LINUX
FLAGS=-std=c++17

TARGET=first

OBJECTS=main.o Game.o Window.o



all: ${TARGET}

## targets
${TARGET} : ${OBJECTS}
	${CC} ${FLAGS} ${INC} ${DEFINES} ${OBJECTS} ${LIBS} -o ${TARGET}

%.o : %.cpp
	${CC} ${FLAGS} ${INC} ${DEFINES} -o $@ -c $<
	
## clean all
clean :
	rm -rf ${TARGET} ${OBJECTS}

.PHONY: clean
