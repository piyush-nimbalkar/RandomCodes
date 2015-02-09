#include <iostream>

using namespace std;

class Node
{
public:
    int weight;
    int dest;
    Node *next;
    Node() { next = NULL; }
    Node(int, int);
};

Node :: Node(int destination, int data)
{
    dest = destination;
    weight = data;
    next = NULL;
}


class AdjList
{
    Node *head;
public:
    AdjList() { head = NULL; }
    void add_node(int, int);
    void display_list();
    ~AdjList() {
        Node *ptr;
        while (head) {
            ptr = head->next;
            delete head;
            head = ptr;
        }
    }
};

void AdjList :: add_node(int destination, int weight)
{
    if (!head)
        head = new Node(destination, weight);
    else {
        Node *ptr = head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new Node(destination, weight);
    }
}

void AdjList :: display_list()
{
    for (Node *ptr = head; ptr; ptr = ptr->next)
        cout << ptr->dest << " = " << ptr->weight << endl;
}


class Graph
{
    int size;
    AdjList *list;
public:
    Graph() { size = 0; list = NULL; }
    Graph(int);
    void add_edge(int, int, int);
    void display();
    ~Graph() { delete[] list; }
};

Graph :: Graph(int vertices)
{
    size = vertices;
    list = new AdjList[size];
}

void Graph :: add_edge(int src, int dest, int weight)
{
    list[src].add_node(dest, weight);
    list[dest].add_node(src, weight);
}

void Graph :: display()
{
    for (int i = 0; i < size; ++i) {
        cout << "Adjacent nodes to " << i << ":" <<endl;
        list[i].display_list();
    }
}


int main(int argc, char *argv[])
{
    int vertices, edges, src, dest, weight;

    cout << "Number of nodes: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; ++i) {
        cout << "Enter (src, dest, weight): ";
        cin >> src >> dest >> weight;
        graph.add_edge(src, dest, weight);
    }

    graph.display();
    return 0;
}
