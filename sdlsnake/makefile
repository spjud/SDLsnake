EXECUTABLE = app
CC = gcc

CFLAGS = -Wall -Wextra -std=gnu99 -ISDL2 -D_REENTRANT -DSDL_MAIN_HANDLED -g -O3
LIBS = -lm -L. -lSDL2

SOURCE = main.c board.c drawline.c
HEADER = board.h drawline.h

include Makefile.in

.PHONY: all
all: $(EXECUTABLE)
$(EXECUTABLE): $(SOURCE) $(HEADER)
	$(info === Compiling...)
	$(shell $(PRE_BUILD))
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBS)


.PHONY: clean
clean:
	@rm -f *.o $(EXECUTABLE) $(TEST_APP) *~ SDL2.dll libSDL2-2.0.so.0
	$(info === Cleaned)
