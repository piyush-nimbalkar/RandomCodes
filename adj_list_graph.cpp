#include <iostream>
#include <utility>
#include <queue>
#include <list>


using namespace std;

const int MAX = 99999;
typedef list<pair<int, int> > Adj;


class Graph
{
    int size;
    Adj *adj;
    void dfs_rec_util(int, bool *);
    void print_path(int, int, int *);
public:
    Graph() { }
    Graph(int size);
    void add_edge(int source, int destination, int weight);
    void remove_edge(int source, int destination);
    void dfs_traversal(int source);
    void bfs_traversal(int source);
    void dijkstra(int source, int destination);
    void kruskals();
    void display();
    ~Graph();
};

Graph :: Graph(int number_of_vertices)
{
    size = number_of_vertices;
    adj = new Adj[size];
}

Graph :: ~Graph()
{
    delete[] adj;
}

void Graph :: add_edge(int source, int destination, int weight)
{
    adj[source].push_back(make_pair(destination, weight));
    adj[destination].push_back(make_pair(source, weight));
}

struct matches
{
    int vertex;
    matches(const int &value): vertex(value) {}
    bool operator() (const pair<int, int> &edge) {
        return (edge.first == vertex);
    }
};

void Graph :: remove_edge(int source, int destination)
{
    adj[source].remove_if(matches(destination));
    adj[destination].remove_if(matches(source));
}

void Graph :: dfs_rec_util(int current, bool *visited)
{
    cout << current << " ";
    visited[current] = true;

    Adj::iterator it;
    for (it = adj[current].begin(); it != adj[current].end(); it++)
        if (!visited[it->first])
            dfs_rec_util(it->first, visited);
}

void Graph :: dfs_traversal(int source)
{
    bool visited[size];

    for (int i = 0; i < size; ++i)
        visited[i] = false;

    dfs_rec_util(source, visited);
}

void Graph :: bfs_traversal(int source)
{
    int current;
    queue<int> q;
    Adj::iterator it;
    bool visited[size];

    for (int i = 0; i < size; ++i)
        visited[i] = false;

    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        current = q.front();
        cout << current << " ";
        q.pop();

        for (it = adj[current].begin(); it != adj[current].end(); it++) {
            if (!visited[it->first]) {
                q.push(it->first);
                visited[it->first] = true;
            }
        }
    }
}

void Graph :: dijkstra(int source, int destination)
{
    int current, dist, next;
    int min_dist, i;
    int previous[size], distance[size];
    bool visited[size];
    Adj::iterator it;

    for (i = 0; i < size; ++i) {
        previous[i] = -1;
        distance[i] = MAX;
        visited[i] = false;
    }

    distance[source] = 0;
    current = source;
    while (current != destination) {
        min_dist = MAX;
        for (it = adj[current].begin(); it != adj[current].end(); it++) {
            dist = distance[current] + it->second;
            if (!visited[it->first] && dist < distance[it->first]) {
                distance[it->first] = dist;
                previous[it->first] = current;
            }
        }

        min_dist = MAX;
        for (i = 0; i < size; ++i) {
            if (!visited[i] && distance[i] < min_dist) {
                min_dist = distance[i];
                next = i;
            }
        }
        visited[current] = true;
        current = next;
    }
    cout << "Shortest Distance: " << min_dist << endl;
    cout << "Shortest Path: ";
    print_path(source, destination, previous);
    cout << endl;
}

void Graph :: print_path(int source, int current, int *previous)
{
    if (current == source) {
        cout << current << " ";
        return;
    }
    print_path(source, previous[current], previous);
    cout << current << " ";
}

void Graph :: kruskals()
{
    Graph mst(size);
    int i, u, v, weight;
    int count = 1, min_weight;
    int parent[size];
    bool visited[size];
    Adj::iterator it;

    for (i = 0; i < size; ++i)
        parent[i] = -1;

    while (count < size) {
        min_weight = MAX;
        for (i = 0; i < size; i++) {
            for (it = adj[i].begin(); it != adj[i].end(); it++) {
                if (it->second < min_weight) {
                    min_weight = it->second;
                    u = i;
                    v = it->first;
                }
            }
        }

        if (min_weight == MAX)
            break;

        if ((parent[u] == -1 && parent[v] == -1) || parent[u] != parent[v]) {
            parent[v] = (parent[u] != -1 ? parent[u] : u);
            weight += min_weight;
            mst.add_edge(u, v, min_weight);
            mst.add_edge(v, u, min_weight);
            count++;
        }
        remove_edge(u, v);
        remove_edge(v, u);
    }
    mst.display();
}

void Graph :: display()
{
    Adj::iterator it;

    cout << "\nEdges: " << endl;
    for (int i = 0; i < size; ++i) {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
            cout << i << " -> " << it->first << " == " << it->second << endl;
        cout << endl;
    }
}


int main(int argc, char *argv[])
{
    int size, source, destination, weight;

    cout << "Enter number of vertices: ";
    cin >> size;
    Graph graph(size);

    cout << "Enter number of edges: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> source >> destination >> weight;
        graph.add_edge(source, destination, weight);
    }

    graph.display();

    // cout << "Enter source for DFS recursive: ";
    // cin >> source;
    // graph.dfs_traversal(source);
    // cout << endl << endl;

    // cout << "Enter source for BFS: ";
    // cin >> source;
    // graph.bfs_traversal(source);
    // cout << endl << endl;

    // cout << "Enter (source, destination) for Dijkstra: ";
    // cin >> source >> destination;
    // graph.dijkstra(source, destination);
    // cout << endl;

    graph.kruskals();

    return 0;
}
