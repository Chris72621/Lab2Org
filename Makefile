CC   = cc
OBJS = ArrayList.o my_string.o tokenizer.0

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: main

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

main: $(OBJS) main.o
	${CC} -o $@ $^

run: main
	./main

clean:
	rm -f *.o main

ArrayList.o: ArrayList.c ArrayList.h
my_string.o: my_string.c my_string.h
tokenizer.o: tokenizer.c tokenizer.h