#include <iostream>

using namespace std;

const int max = 10;

class Node
{
    int weight;
    int number_of_neighbors;
    Node *adjacent[max];
public:
    Node();
    Node(int);
};

Node :: Node()
{
    number_of_neighbors = 0;
    adjacent = NULL;
}

Node :: Node(int wt)
{
    weight = wt;
    number_of_neighbors = 0;
    adjacent = NULL;
}
