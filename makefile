CC := g++
TARGET := main

# Detect the operating system
VCPKG_PATH := D:/study/PLAYGROUND/C++/C++/vcpkg

ifeq ($(OS),Windows_NT)

	# 设置编译器标志，包含 vcpkg 路径
	CFLAGS := -O2 -std=c++14 -Wall -c -fpermissive -fconserve-space -Wno-write-strings -I$(VCPKG_PATH)/installed/x64-windows/include

	# 设置链接标志，包含 vcpkg 路径
	LFLAGS := -lgdi32 -L$(VCPKG_PATH)/installed/x64-windows/lib

	# 目标文件扩展名和清理命令
	EXTENSION := .exe
	CLEANUP := del
	CLEANUP_OBJS := del *.o

	# 定义源文件和头文件
	SRCS := main.cpp graphics.cpp transform.cpp sprites.cpp fuzzylogic.cpp
	HDRS := graphics.h transform.h sprites.h fuzzylogic.h

else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		# macOS
		EXTENSION := .out
		CFLAGS := -O2 -std=c++14 -Wall -I/usr/local/include -L/usr/local/lib -c -Wno-write-strings
		LFLAGS := -L/usr/local/lib -lSDL_bgi -lSDL2 
		CLEANUP := rm -f
		CLEANUP_OBJS := rm -f *.o

		# Find all source files (.cpp) and header files (.h)
		SRCS := main.cpp transform.cpp sprites.cpp fuzzylogic.cpp 
		HDRS := transform.h sprites.h fuzzylogic.h
		
	else ifeq ($(UNAME_S),Linux)
		# Linux
		EXTENSION := .out
		CFLAGS := -O2 -std=c++14 -Wall -I/usr/local/include -L/usr/local/lib -c -Wno-write-strings  
		LFLAGS := -lSDL_bgi -lSDL2 
		CLEANUP := rm -f
		CLEANUP_OBJS := rm -f *.o

		# Find all source files (.cpp) and header files (.h)
		SRCS := main.cpp transform.cpp sprites.cpp fuzzylogic.cpp 
		HDRS := transform.h sprites.h fuzzylogic.h
	endif
endif



# Create object file names based on source file names
OBJS := $(SRCS:.cpp=.o)


# Rule to build the executable
$(TARGET)$(EXTENSION): $(OBJS)
	$(CC) -O2 -std=c++14 -o $@ $(OBJS) $(LFLAGS)

# Rule to build object files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(CLEANUP) $(TARGET)$(EXTENSION)
	$(CLEANUP_OBJS)
