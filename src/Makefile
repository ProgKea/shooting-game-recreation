CC=gcc
CC_CROSS=x86_64-w64-mingw32-gcc
LIBS=`pkg-config --cflags --libs sdl2` -lSDL2_mixer -lSDL2_ttf -lSDL2_image -lm
CFLAGS=-Wall -pedantic -Wshadow -Werror 
CFLAGS_CROSS=-mwindows
OPT_FLAGS=-s -O2
DEPENDENCIES=../src/*.c
PROJECT=bad_game

${PROJECT}: ${DEPENDENCIES}
	${CC} ${CFLAGS} ${DEPENDENCIES} -o ../build/${PROJECT} ${LIBS}

cross: ${DEPENDENCIES}
	${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} ${DEPENDENCIES} -o ../build/windows/${PROJECT} ${LIBS}

opt: ${DEPENDENCIES}
	${CC} ${CFLAGS} ${OPT_FLAGS} ${DEPENDENCIES} -o ../build/${PROJECT} ${LIBS}

release: ${DEPENDENCIES}
	${CC} ${CFLAGS} ${OPT_FLAGS} *.c -o ../build/${PROJECT} ${LIBS} && ${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} ${OPT_FLAGS} ${DEPENDENCIES} -o ../build/windows/${PROJECT} ${LIBS}

run: 
	make && ../build/${PROJECT}
