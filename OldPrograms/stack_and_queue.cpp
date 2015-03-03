#include <iostream>
#include <queue>

using namespace std;

const int size = 100;

template <typename T>
class Stack
{
    queue<T> q;
public:
    void push(T value);
    T pop();
};

template <typename T>
void Stack<T> :: push(T value)
{
    q.push(value);
}

template <typename T>
T Stack<T> :: pop()
{
    int count;
    T item;

    if (q.empty())
        throw "Stack overflow!";

    count = q.size();
    for (int i = 0; i < count - 1; i++) {
        q.push(q.front());
        q.pop();
    }

    item = q.front();
    q.pop();
    return item;
}

int main(int argc, char *argv[])
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    try {
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
    } catch(const char* str) {
        cout << str << endl;
    }
    return 0;
}
