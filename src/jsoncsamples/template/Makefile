CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
CFLAGS=\
       `pkg-config --cflags json-c`
LDFLAGS=\
       `pkg-config --libs json-c`\
       -llog
$(BIN):$(SRC)
	$(CC)\
		$(CFLAGS)\
		$(SRC)\
		$(LDFLAGS)\
		-o $(BIN)
.phony:\
	clean\
	run
clean:
	rm $(BIN)
run:
	$(BIN)

