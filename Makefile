CPP=g++
CPPFLAGS=--std=c++11 -c
OFLAGS=-o ./build/
all: build/app

build/app: build/main.o
	 g++ build/*.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: build/resource_holder.o build/textures.o build/game.o
	 $(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/game.o: build/resource_holder.o build/textures.o build/hero.o build/entity.o
	 $(CPP) $(CPPFLAGS) src/game.cpp $(OFLAGS)game.o

build/hero.o: build build/entity.o
	 $(CPP) $(CPPFLAGS) src/hero.cpp $(OFLAGS)hero.o

build/entity.o: build build/resource_holder.o build/scene_node.o
	 $(CPP) $(CPPFLAGS) src/entity.cpp $(OFLAGS)entity.o

build/scene_node.o: build
	 $(CPP) $(CPPFLAGS) src/scene_node.cpp $(OFLAGS)scene_node.o

build/textures.o: build
	 g++ -c src/textures.cpp $(OFLAGS)textures.o

build/resource_holder.o: build
	 $(CPP) $(CPPFLAGS) src/resource_holder.cpp $(OFLAGS)resource_holder.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
