# Set compiler.
# CC=gcc
CXX:=g++

# Set flags.
# CFLAGS=
CXXFLAGS:=-Wall -O3 -std=c++17
DEPFLAGS:=-MD -MP # Autogenerate dependencies.
CPPFLAGS:=-DVALUE=1
LDFLAGS:=-lm
# INCLUDES:=

# Directories.
BUILD_DIR:=build
SRC_DIR:=src
OBJ_DIR:=$(BUILD_DIR)/obj

# Files.
SRCS:=$(shell find $(SRC_DIR) -name "*.cpp")
OBJS:=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:%.cpp=%.o))
DEPS:=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:%.cpp=%.d))

#
# Executables.
#
MAIN:=$(BUILD_DIR)/main
MAIN_OBJS:=main.o
MAIN_OBJS:=$(addprefix $(OBJ_DIR)/, $(MAIN_OBJS)) # Append the OBJ_DIR to the objets.

#
# Generate executables
#
$(MAIN): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

#
# Generate objects.
#
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(INCLUDES) $(DEPFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Include dependencies.
-include $(DEPS)

# The default goal is the next goal.
.DEFAULT_GOAL:=
.PHONY: all
all: main

main: $(MAIN)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*
