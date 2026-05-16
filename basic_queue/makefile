
# DIRECTORIES
BUILD_DIR := build
BIN_DIR   := $(BUILD_DIR)/bin
OBJ_DIR   := $(BUILD_DIR)/obj
SRC_DIR   := src
INC_DIR   := include

# TARGET
TARGET    := $(BIN_DIR)/main

# SOURCES
APP_SRC   := $(SRC_DIR)/main.c
LIB_SRCS  := $(filter-out $(APP_SRC), $(wildcard $(SRC_DIR)/*.c))

SRCS      := $(APP_SRC) $(LIB_SRCS)

# OBJECTS
OBJS      := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# COMPILER
CC := clang

CFLAGS    := -std=c11 \
		  -Werror -Wextra -Wpedantic \
		  -fstack-protector-strong -g -o0 \
		  -I$(INC_DIR) \
		  -MMD -MP

# DEPENDENCIES
DEPS := $(OBJS:.o=.d)

# RULES
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all run clean re

# LINKING
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# COMPILATION
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# DIRECTORIES
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

# AUTO DEPENDENCIES
-include $(DEPS)
