CC = cc
OBJS = my_string.o tokenizer.o ArrayList.o
CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: main

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

compile: $(OBJS)

main: $(OBJS) main.o
	${CC} -o $@ $^

run: main
	./main

clean:
	rm -f *.o main

my_string.o: my_string.c my_string.h
tokenizer.o: tokenizer.c tokenizer.h my_string.h
ArrayList.o: ArrayList.h ArrayList.c
