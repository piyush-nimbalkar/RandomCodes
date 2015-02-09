#include <iostream>

using namespace std;


const int MAX = 99999;

class Graph
{
    int size;
    int **matrix;
    bool edge_present(int, int);
    void print_shortest_path(int *, int, int);
public:
    Graph() { }
    Graph(int);
    void get_input();
    void dijkstra(int, int);
    ~Graph();
};

Graph :: Graph(int num)
{
    size = num;
    matrix = new int * [size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new int[size];
}

Graph :: ~Graph()
{
    for (int i = 0; i < size; ++i)
        delete matrix[i];
    delete matrix;
}

void Graph :: get_input()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> matrix[i][j];
}

bool Graph :: edge_present(int source, int destination)
{
    return (matrix[source][destination] > 0 ? true : false);
}

void Graph :: dijkstra(int source, int destination)
{
    int current = source;
    int dist, min_dist = MAX;
    int distance[size], previous[size];
    bool visited[size];
    int i, j;

    for (i = 0; i < size; ++i) {
        distance[i] = MAX;
        previous[i] = -1;
        visited[i] = false;
    }
    distance[source] = 0;

    while (current != destination) {
        for (i = 0; i < size; ++i) {
            if (!visited[i] && edge_present(current, i)) {
                dist = distance[current] + matrix[current][i];
                if (dist < distance[i]) {
                    distance[i] = dist;
                    previous[i] = current;
                }
            }
        }

        min_dist = MAX;
        for (i = 0; i < size; ++i) {
            if (!visited[i] && min_dist > distance[i]) {
                min_dist = distance[i];
                current = i;
            }
        }
        visited[current] = true;
    }

    cout << "Distances: ";
    for (i = 0; i < size; ++i)
        cout << distance[i] << "  ";
    cout << endl;

    cout << "Shortest Path: ";
    print_shortest_path(previous, source, destination);
    cout << endl;
}

void Graph :: print_shortest_path(int *previous, int source, int destination)
{
    if (source == destination) {
        cout << source << "  ";
        return;
    }
    print_shortest_path(previous, source, previous[destination]);
    cout << destination << "  ";
}


int main(int argc, char *argv[])
{
    int size;

    cout << "Enter number of vertices: ";
    cin >> size;
    Graph graph(size);

    cout << "Enter adjacency matrix:\n";
    graph.get_input();

    int source, destination;
    cout << "Enter (source, destination): ";
    cin >> source >> destination;
    graph.dijkstra(source, destination);

    return 0;
}
