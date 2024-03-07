OBJS	= main.o PriorityQueue.o AdjacencyList.o
SOURCE	= main.cc PriorityQueue.cc AdjacencyList.cc
HEADER	= PriorityQueue.h AdjacencyList.h
OUT	= ds3
CC	 = g++
FLAGS	 = -g -std=c++14 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cc
	$(CC) $(FLAGS) main.cc 

PriorityQueue.o: PriorityQueue.cc
	$(CC) $(FLAGS) PriorityQueue.cc 

AdjacencyList.o: AdjacencyList.cc
	$(CC) $(FLAGS) AdjacencyList.cc 


clean:
	rm -f $(OBJS) $(OUT)

