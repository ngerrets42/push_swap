# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ngerrets <ngerrets@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 14:47:03 by ngerrets      #+#    #+#                  #
#    Updated: 2021/09/20 18:02:57 by ngerrets      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# For now this is the default Makefile I use for C projects
# Manually edit:

NAME := push_swap
CHECKER := checker

COMPILE_FLAGS ?= -Wall -Wextra -Werror
LINKING_FLAGS ?= -Llib/get_next_line -lgnl
LIBRARIES ?=
SOURCE_DIRECTORY ?= src
HEADER_DIRECTORY ?= include
OBJECTS_DIRECTORY ?= objects
BINARIES_DIRECTORY ?= .

# Don't manually edit:
SOURCES :=
include sources_pushswap.mk
SOURCES_CHECKER :=
include sources_checker.mk

HEADERS	:= $(shell find $(HEADER_DIRECTORY) -type f -name *.h)
INCLUDES := $(patsubst %,-I%,$(dir $(HEADERS)))
OBJECTS := $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(SOURCES:.c=.o))
OBJECTS_CHECKER := $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(SOURCES_CHECKER:.c=.o))
NAME := $(BINARIES_DIRECTORY)/$(NAME)

# Default make-rule. Compile and link files.
all: _pushswap _checker

_pushswap: $(NAME)

_checker: $(CHECKER)

# Link files
$(BINARIES_DIRECTORY)/$(NAME): $(BINARIES_DIRECTORY) $(HEADERS) $(OBJECTS)
	@echo "\nBuilding dependencies..."
	@$(MAKE) dependencies
	@echo "\nLinking files push_swap..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

# Link files CHECKER
$(BINARIES_DIRECTORY)/$(CHECKER): $(BINARIES_DIRECTORY) $(HEADERS) $(OBJECTS_CHECKER)
	@echo "\nBuilding dependencies..."
	@$(MAKE) dependencies
	@echo "\nLinking files checker..."
	@$(CC) $(OBJECTS_CHECKER) -o $(CHECKER) $(LINKING_FLAGS)
	@echo "Done!"

dependencies:
	@$(MAKE) -C lib/get_next_line

# Create binaries directory
$(BINARIES_DIRECTORY):
	@mkdir -p $(BINARIES_DIRECTORY)

# Compile files
$(OBJECTS_DIRECTORY)/%.o: %.c $(HEADERS)
	@echo "Compiling: $<"
	@mkdir -p $(@D)
	@$(CC) $(COMPILE_FLAGS) $(INCLUDES) -c -o $@ $<

# Clean objects
clean: cleandeps
	@echo "Cleaning objects..."
	@rm -Rf $(OBJECTS_DIRECTORY)
	@echo "Objects cleaned."

cleandeps:
	@echo "Cleaning dependencies..."
	@$(MAKE) -C lib/get_next_line clean

# Clean objects and binaries
fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@rm -f *.a
	@echo "Binaries cleaned."

# Clean, recompile and relink project
re: fclean all

# Prints header and source files
print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---SOURCES: $(SOURCES_CHECKER)" | xargs -n1

# In case of bonus
bonus: all

.PHONY: all dependencies clean cleandeps fclean re print bonus _checker _pushswap