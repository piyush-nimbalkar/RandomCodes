#include <iostream>
#include <queue>

using namespace std;

const int size = 100;

class Stack
{
    queue<int> q;

public:
    void push(int value);
    int pop();
};

void Stack :: push(int value)
{
    q.push(value);
}

int Stack :: pop()
{
    int count, item;

    if (q.empty())
        return -1;

    count = q.size();
    for (int i = 0; i < count - 1; i++) {
        q.push(q.front());
        q.pop();
    }

    item = q.front();
    q.pop();
    return item;
}
