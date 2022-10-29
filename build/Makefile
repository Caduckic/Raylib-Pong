default:
ifdef web
	ifdef linux
		emcc ../src/main.cpp ../src/include/jsoncpp.cpp -o game.html -Os -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/web/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -s USE_GLFW=3 --shell-file path-to/shell.html -DPLATFORM_WEB
	else if
		emcc ../src/main.cpp -o game.html -Os -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/web/ -lraylib -s USE_GLFW=3 -s ASYNCIFY --shell-file ./shell.html -DPLATFORM_WEB --preload-file ../src/audio -sEXPORTED_RUNTIME_METHODS=ccall
	endif
else
	ifdef linux
		g++ ../src/main.cpp ../src/include/jsoncpp.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/desktop/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	else
		g++ ../src/main.cpp ../src/include/jsoncpp.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/desktop/ -lraylib -lopengl32 -lgdi32 -lwinmm
	endif
endif