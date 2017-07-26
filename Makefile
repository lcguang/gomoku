CC=g++
OPTS=-g -std=c++11 -Wall

all: logger_test.o logger.o
	$(CC) $(OPTS) -lm -o logger_test logger_test.o logger.o

logger_test.o: logger_test.cpp logger.h
	$(CC) $(OPTS) -c logger_test.cpp

logger.o: logger.cpp logger.h
	$(CC) $(OPTS) -c logger.cpp

clean:
	rm -f *.o logger_test;