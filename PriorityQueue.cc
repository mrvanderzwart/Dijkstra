#ifndef PriorityQueueCCVar
#define PriorityQueueCCVar

#include <iostream>
#include <fstream>
#include <climits>
#include "PriorityQueue.h"

bool PriorityQueue::isEmpty()
{
  return heap.empty();
}

void PriorityQueue::bubbleUp(int i)
{
  int parent = (i-1)/2;
  if (parent >= 0 && heap[i].second < heap[parent].second)
  {
    swap(heap[i], heap[parent]);
    bubbleUp(parent);
  }
}

void PriorityQueue::trickleDown(int i)
{
  int lchild = 2 * i + 1;
  int rchild = 2 * i + 2;
  if (i < static_cast<int>(heap.size()))
  {
    if (lchild < static_cast<int>(heap.size()) &&
        heap[lchild].second <= heap[rchild].second &&
        heap[lchild].second < heap[i].second)
    {
      swap(heap[i], heap[lchild]);
      trickleDown(lchild);
    }
    else if (rchild < static_cast<int>(heap.size()) &&
             heap[rchild].second <= heap[lchild].second &&
             heap[rchild].second < heap[i].second)
    {
      swap(heap[i], heap[rchild]);
      trickleDown(rchild);
    }
  }
}

void PriorityQueue::insert(int newItem, int prio)
{
  heap.push_back(std::make_pair(newItem,prio));
  bubbleUp(static_cast<int>(heap.size()-1));
}

int PriorityQueue::getMinimum()
{
  return heap[0].first;
}

void PriorityQueue::deleteMinimum()
{
  int last1 = heap[heap.size()-1].first;
  int last2 = heap[heap.size()-1].second;
  heap[0].first = last1;
  heap[0].second = last2;
  heap.erase(heap.begin()+heap.size()-1);
  trickleDown(0);
}

void PriorityQueue::showDistance(int distance[], std::string outfile)
{
  std::ofstream output;
  std::string filename2 = outfile + ".dis";

  output.open(filename2);
  for (int i = 1; i <= nEdges; i++)
  {
    output << i;
    output.put(' ');
    if (distance[i] != INT_MAX)
    {
      output << distance[i];
    }
    else
    {
      output.put('-');
    }
    output.put('\n');
  }
  std::cout << "Output has been written to " << filename2 << std::endl;
}

void PriorityQueue::performDijkstra(std::string outfile, int startingPoint, int numEdges, std::vector<std::vector<AdjacencyList::edge>> &ajList)
{ 
  src = startingPoint;
  nEdges = numEdges;
  int distance[nEdges];
  bool visited[nEdges];
  heap.push_back(std::make_pair(src, 0));
  
  for (int i = 1; i <= nEdges; i++)
  {
    distance[i] = INT_MAX;
    visited[i] = false;
  }
  distance[src] = 0;

  while (!isEmpty())
  {
    int u = getMinimum();
    deleteMinimum();
    visited[u] = true;
    for (unsigned v = 0; v < ajList[u].size(); v++)
    {
      if (!visited[ajList[u][v].num] && distance[u] != INT_MAX
          && distance[u] + ajList[u][v].dist < distance[ajList[u][v].num])
      {
        distance[ajList[u][v].num] = distance[u] + ajList[u][v].dist;
        insert(ajList[u][v].num, distance[ajList[u][v].num]);
      }
    }
  }
  showDistance(distance, outfile);
}

#endif

