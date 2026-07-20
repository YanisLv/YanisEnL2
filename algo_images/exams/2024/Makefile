CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJDIR = obj
BIN = otsu

SRC = pgm.c otsu.c main.c 
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))

all: $(OBJDIR) $(BIN)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des .c en .o dans obj/
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BIN)
