all: build/app

build/app: build/main.o
	 g++ build/*.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: build/resource_holder.o build/textures.o build/game.o
	 g++ -std=c++11 -c main.cpp -o ./build/main.o

build/game.o: build/resource_holder.o build/textures.o build/hero.o build/entity.o
	 g++ -std=c++11 -c src/game.cpp -o ./build/game.o

build/hero.o: build build/entity.o
	 g++ -std=c++11 -c src/hero.cpp -o ./build/hero.o

build/entity.o: build build/resource_holder.o
	 g++ -std=c++11 -c src/entity.cpp -o ./build/entity.o

build/textures.o: build
	 g++ -c src/textures.cpp -o ./build/textures.o

build/resource_holder.o: build
	 g++ -std=c++11 -c src/resource_holder.cpp -o ./build/resource_holder.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
