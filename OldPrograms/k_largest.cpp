#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef priority_queue <int, vector<int>, greater<int> > min_heap;

void display(min_heap q)
{
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}


int main(int argc, char *argv[])
{
    int arr[10] = {11, 2, 30, 4, 5, 6, 7, 18, 9, 10};
    min_heap q;

    for (int i = 0; i < 10; i++) {
        if (q.size() >= 5) {
            if (q.top() < arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        } else
            q.push(arr[i]);
    }
    display(q);
    return 0;
}
