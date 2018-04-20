CPP=g++
CPPFLAGS=--std=c++11 -c
OFLAGS=-o ./build/
all: build/app

build/app: build/main.o
	 g++ build/*.o -o build/app -lsfml-graphics -lsfml-window -lsfml-system

build/main.o: build/resource_holder.o build/textures.o build/game.o
	 $(CPP) $(CPPFLAGS) main.cpp $(OFLAGS)main.o

build/game.o: build/world.o build/game_input_handler.o
	 $(CPP) $(CPPFLAGS) src/game.cpp $(OFLAGS)game.o

build/game_input_handler.o: build/command_queue.o build/command.o build/category.o
	  $(CPP) $(CPPFLAGS) src/game_input_handler.cpp $(OFLAGS)game_input_handler.o

build/world.o: build/scene_node.o build/hero.o build/textures.o build/command_queue.o
	 $(CPP) $(CPPFLAGS) src/world.cpp $(OFLAGS)world.o

build/hero.o: build build/entity.o build/textures.o
	 $(CPP) $(CPPFLAGS) src/hero.cpp $(OFLAGS)hero.o

build/entity.o: build build/scene_node.o
	 $(CPP) $(CPPFLAGS) src/entity.cpp $(OFLAGS)entity.o

build/scene_node.o: build build/resource_holder.o build/textures.o build/category.o build/command.o
	 $(CPP) $(CPPFLAGS) src/scene_node.cpp $(OFLAGS)scene_node.o

build/game_input_handler.o: build build/command_queue.o
	 $(CPP) $(CPPFLAGS) src/game_input_handler.cpp $(OFLAGS)game_input_handler.o

build/command_queue.o: build build/command.o
	 $(CPP) $(CPPFLAGS) src/command_queue.cpp $(OFLAGS)command_queue.o

build/command.o: build
	 $(CPP) $(CPPFLAGS) src/command.cpp $(OFLAGS)command.o

build/category.o: build
	 g++ -c src/category.cpp $(OFLAGS)category.o

build/textures.o: build
	 g++ -c src/textures.cpp $(OFLAGS)textures.o

build/resource_holder.o: build
	 $(CPP) $(CPPFLAGS) src/resource_holder.cpp $(OFLAGS)resource_holder.o

build:
	 mkdir -p build

clean:
	 rm -rf ./build
