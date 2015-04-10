#include <iostream>
#include <iostream>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int mcm(vector<pair<int, int> > &M, int start, int end)
{
    if (start >= end)
        return 0;
    int min_cost = numeric_limits<int>::max();
    for (int k = start; k < end; k++)
        min_cost = min(min_cost, mcm(M, start, k) + mcm(M, k+1, end) + (M[start].first * M[k].second * M[end].second));
    return min_cost;
}


int main(int argc, char *argv[])
{
    vector<pair<int, int> > M;
    M.push_back(make_pair(4, 2));
    M.push_back(make_pair(2, 3));
    M.push_back(make_pair(3, 1));
    M.push_back(make_pair(1, 3));

    cout << "Minimum multiplications: " << mcm(M, 0, M.size()-1) << endl;

    return 0;
}
