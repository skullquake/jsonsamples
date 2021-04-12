CXX=g++
CFLAGS=\
	-I./include\
	`pkg-config --cflags jsoncpp`
LIBS=\
	-L./lib\
	`pkg-config --libs jsoncpp`
SRC=./src/a.cpp
BIN=./bin/a
$(BIN):$(SRC)
	$(CXX)\
		$(CFLAGS)\
		$(SRC)\
		$(LIBS)\
		-o $(BIN)
.phony:\
	run\
	clean
run:
	printf '{\n\t"foo":"bar",\n\t"baz":"qux"\n}'|$(BIN)
clean:
	rm ./bin/*
