CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = bin/wl-yoink
SRC     = $(wildcard src/*.c)
OBJ     = $(patsubst src/%.c, build/%.o, $(SRC))

$(TARGET): $(OBJ) | bin
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

bin build:
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf build bin

PREFIX  = /usr/local
BINDIR  = $(PREFIX)/bin

install: $(TARGET)
	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/myprogram

.PHONY: clean install uninstall
