all: parser.cpp lexer.cpp
	clang++ parser.cpp  lexer.cpp -o parser -Wall -g -O0

clean:
	rm -f parser
