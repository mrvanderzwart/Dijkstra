#include <iostream>
#include "PriorityQueue.h"
#include "AdjacencyList.h"

void mainMenu()
{
  char input;
  int startingPoint;
  std::string filename;
  std::vector<std::vector<AdjacencyList::edge>> adjList;
  do
  {
    std::cout << std::endl;
    std::cout << "1. Execute shortest path algorithm" << std::endl;
    std::cout << "2. Quit" << std::endl << std::endl;
    std::cout << "Input: ";
    std::cin >> input;
    switch (input)
    {
      case '1':
        {
          AdjacencyList* A = new AdjacencyList();
          PriorityQueue* PQ = new PriorityQueue();
          std::cout << "Enter valid file name: ";
          std::cin >> filename;
          std::cout << "Enter starting point: ";
          std::cin >> startingPoint;
          std::cout << std::endl;
          A->createAdjList(filename, adjList);
          PQ->performDijkstra(filename, startingPoint, A->get_nEdges(), adjList);

          delete A;
          delete PQ;
          break;
        }
      case '2':
      {
        break;
      }
      default:
        std::cout << "Enter a valid option";
        std::cout << std::endl;
        break;
    }
  }
  while (input != '2');
}

int main()
{
  mainMenu();
  return 0;
}


