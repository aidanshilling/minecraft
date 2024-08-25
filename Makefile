.DEFAULT_GOAL=main

main: ./include/GLFW/glfw3.h build/glad.o build/opengl-utils.o ./include/glad/glad.h
	clang -I ./include/ -L ./lib/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit ./src/main.c ./build/glad.o ./build/opengl-utils.o -o ./build/main

build/glad.o: ./include/glad/glad.h
	clang -c -arch arm64 -I ./include/ ./src/glad.c -o build/glad.o

build/opengl-utils.o: ./src/opengl-utils.h
	clang -c -arch arm64 -I ./include/ ./src/opengl-utils.c -o build/opengl-utils.o

run: main
	./build/main
