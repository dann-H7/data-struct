# Makefile for bash

# Directories
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin
SRC_DIR   := src
INC_DIR   := include

# source main
APP_SRCS := $(SRC_DIR)/main.c 

# Objects
APP_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(APP_SRCS))
LIB_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter-out $(APP_SRCS), $(wildcard $(SRC_DIR)/*.c)))
OBJS     := $(APP_OBJS) $(LIB_OBJS)

# main target
TARGET := $(BIN_DIR)/main.exe

# Toolchain
CC     := clang
CFLAGS := -std=c11 \
		-Wall -Wextra -Werror -Wpedantic \
		-fstack-protector-strong -g -o0 -I$(INC_DIR) -MMD -MP

# logic
all: build run

build: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

re: clean all

# Phony
.PHONY: all build run clean re

# folders buiding (order-only)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# sources compilation -> objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# tests compilation -> objets
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# main.exe linking (included main.o + lib objs)
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# include dependance auto-gen
-include $(OBJS:.o=.d) $(TEST_OBJ:.o=.d)
