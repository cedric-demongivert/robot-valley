BINARIES_DIR = ./bin
SOURCES_DIR = ./src
HEADERS_DIR = ./src/headers
LIBS_DIR = ./libs
OBJS_DIR = ./bin/obj

CC = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -I$(HEADERS_DIR) #-L$(LIBS_DIR) $(addprefix -l, $(LIBS))

LIBS =

SRCS = $(shell find -name "*.cpp" -type f -printf " %h/%f") #! -name "$(MAIN)"
HEADERS = $(SRCS:.cpp=.hpp)

EXE_NAME = tp.exe

OBJS_TMP = $(SRCS:.cpp=.o)
OBJS = $(subst $(SOURCES_DIR), ., $(OBJS_TMP))

build: $(BINARIES_DIR) $(OBJS)
	$(CC) -o $(BINARIES_DIR)/$(EXE_NAME) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(CXXFLAGS)

clean:
	rm -R $(BINARIES_DIR)

$(BINARIES_DIR):
	mkdir -p $(BINARIES_DIR)

$(OBJS_DIR): $(BINARIES_DIR)
	mkdir -p $(OBJS_DIR)
	mkdir -p $(BINARIES_DIR)/tests

%.o: $(SOURCES_DIR)/%.cpp $(OBJS_DIR)
	$(CC) -c $< -o $(OBJS_DIR)/$@ $(CXXFLAGS)
