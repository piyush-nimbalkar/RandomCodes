#include <iostream>

using namespace std;


int rec_find_depth(int *depth, int *parent, int i, int &max_depth)
{
    if (i == -1)
        return 0;

    if (depth[i] != 0)
        return depth[i];

    depth[i] = 1 + rec_find_depth(depth, parent, parent[i], max_depth);

    if (depth[i] > max_depth)
        max_depth = depth[i];

    return depth[i];
}


void find_depth(int *parent, int size)
{
    int max_depth = 0;
    int *depth = new int[size];

    for (int i = 0; i < size; i++)
        depth[i] = 0;

    for (int i = 0; i < size; i++)
        rec_find_depth(depth, parent, i, max_depth);

    cout << "Depth: " << max_depth << endl;
}


int main(int argc, char *argv[])
{
    int size = 10;
    int parent[] = {3, -1, 3, 1, 5, 1, 0, 4, 2, 6};

    find_depth(parent, size);

    return 0;
}
