SRC = test.c
OBJ = $(SRC:.c=.o)
OUT = test
INCLUDES = -I.

.SUFFIXES: .c

default: $(OUT)

.c.o:
	gcc -c $< -o $@

$(OUT): $(OBJ)
	gcc -o $(OUT) $(OBJ)

clean:
	rm -rf *.o test
