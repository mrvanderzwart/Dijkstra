#ifndef PriorityQueueHVar
#define PriorityQueueHVar

#include <vector>
#include "AdjacencyList.h"

class PriorityQueue
{
  public:

    /**
    * @function bool isEmpty
    * @abstract checks if the heap is empty
    * @param 	void
    * @return 	true if the heap is empty, false if it isn't
    * @pre 		An initialized heap
    * @post 	-
    **/
    bool isEmpty();

    /**
    * @function void bubbleUp
    * @abstract heapifies tree after insertion
    * @param void
    * @return void
    * @pre heap possible not satisfying heap-ordening
    * @post heap satisfying heap-ordening
    **/
    void bubbleUp(int i);

    /**
    * @function void trickleDown
    * @abstract heapifies tree after deletion
    * @param void
    * @return void
    * @pre heap possible not satisfying heap-ordening
    * @post heap satisfying heap-ordening
    **/
    void trickleDown(int i);

    /**
    * @function void insert
    * @abstract Inserts a new element in the heap with priority
    * @param 	number of the newItem and its priority
    * @return 	void
    * @pre 		Initialized heap
    * @post 	New element has been inserted (heap is not sorted yet)
    **/
    void insert(int newItem, int prio);

    /**
    * @function int getMinimum
    * @abstract gets the smallest element from the heap (the root)
    * @param 	void
    * @return 	the value of the smallest element (the root)
    * @pre 		a heap with an element
    * @post 	minimum element has been returned
    **/
    int getMinimum();

    /**
    * @function void deleteMinimum
    * @abstract replaces the root with the last element of the heap, then
          deletes the last element and heapifies
    * @param 	void
    * @return 	void
    * @pre 		heap with root and last element
    * @post 	same heap but new minimum
    **/
    void deleteMinimum();

    /**
    * @function	void showDistance
    * @abstract writes minimum distances to output file
    * @param 	array with all the distances
    * @return   void
    * @pre 		distances have been determined
    * @post     distances have been written to the output file
    **/
    void showDistance(int distance[], std::string outfile);

    /**
    * @function void performDijkstra
    * @abstract executes the dijkstra algorithm
    * @param 	void
    * @return   void
    * @pre      valid adjacency list
    * @post     shortest paths have been written to output file
    **/
    void performDijkstra(std::string outfile, int startingPoint, int numEdges,
                         std::vector<std::vector<AdjacencyList::edge>> &ajList);

  private:
  
    int src; // first node
    std::vector<std::pair<int,int>> heap;

    int nEdges;

};

#endif


