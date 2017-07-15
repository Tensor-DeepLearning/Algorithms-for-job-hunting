CC = g++
CFLAG = -g -std=c++11 -Wall
DIR_INC = $(wildcard ./code/*.h)
DIR_SRC = $(wildcard ./*.cpp)

TARGET  = Algs
OBJECTS = $(patsubst %.cpp, %.o, $(DIR_SRC))

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(CLIBS)
$(OBJECTS) : %.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@ $(DIR_INC)

.PHONY : clean
clean:
	@rm -rf *.o $(TARGET)


