default:
ifdef linux
	g++ ../src/main.cpp ../src/include/jsoncpp.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else
	g++ ../src/main.cpp ../src/include/jsoncpp.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I ../src/include/ -L  ../src/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
endif