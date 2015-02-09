#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef list<pair<int, int> > Adj;

class Graph
{
    int size;
    Adj *adj;
    void visit(int node, bool* visited, bool *temp, list<int> &topo);
public:
    Graph() { }
    Graph(int size);
    void add_edge(int source, int dest, int weight);
    void display();
    void toposort();
    ~Graph();
};

Graph :: Graph(int _size)
{
    size = _size;
    adj = new Adj[size];
}

Graph :: ~Graph()
{
    delete[] adj;
}

void Graph :: add_edge(int source, int dest, int weight)
{
    adj[source].push_back(make_pair(dest, weight));
}

void Graph :: toposort()
{
    bool *visited = new bool[size]();
    bool *temp = new bool[size]();
    list<int> topo;

    for (int i = 0; i < size; i++)
        if (!visited[i] && adj[i].size() > 0)
            visit(i, visited, temp, topo);

    for (list<int>::iterator it = topo.begin(); it != topo.end(); it++)
        cout << *it << "  ";
    cout << endl;
}

void Graph :: visit(int current, bool *visited, bool *temp, list<int> &topo)
{
    if (temp[current])
        return;

    if (!visited[current]) {
        temp[current] = true;
        for (Adj::iterator it = adj[current].begin(); it != adj[current].end(); it++)
            visit(it->first, visited, temp, topo);
        visited[current] = true;
        temp[current] = false;
        topo.push_front(current);
    }
}

void Graph :: display()
{
    Adj::iterator it;

    cout << "\nEdges: " << endl;
    for (int i = 0; i < size; ++i)
        for (it = adj[i].begin(); it != adj[i].end(); it++)
            cout << i << " -> " << it->first << " == " << it->second << endl;
}


void create_graph_from_dict(vector<string> words, Graph &graph)
{
    int k;
    string current, next;
    if (words.size() == 0)
        return;
    current = words[0];
    for (int i = 1; i < words.size(); i++) {
        next = words[i];
        k = 0;
        while ((int)current[k] != 0 && (int)next[k] != 0 && current[k] == (int)next[k])
            k++;
        if ((int)current[k] != 0 && (int)next[k] != 0)
            graph.add_edge((int)current[k] - 97, (int)next[k] - 97, 0);
        current = next;
    }
}

int main(int argc, char *argv[])
{
    // int size, source, destination, weight;

    // cout << "Enter number of vertices: ";
    // cin >> size;
    // Graph graph(size);

    // cout << "Enter number of edges: ";
    // cin >> size;

    // for (int i = 0; i < size; ++i) {
        // cin >> source >> destination >> weight;
        // graph.add_edge(source, destination, weight);
    // }

    int size;
    string input;
    vector<string> words;

    cout << "Enter number of strings: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> input;
        words.push_back(input);
    }

    Graph graph(26);
    create_graph_from_dict(words, graph);

    graph.display();
    graph.toposort();

    return 0;
}
