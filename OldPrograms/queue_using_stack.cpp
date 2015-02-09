#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
    stack<int> in, out;

public:
    void enqueue(int);
    int dequeue();
};

void MyQueue :: enqueue(int element)
{
    in.push(element);
}

int MyQueue :: dequeue()
{
    int element;

    if(out.empty())
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }

    if(!out.empty()) {
        element = out.top();
        out.pop();
    } else {
        element = -1;
    }
    return element;
}


int main(int argc, char *argv[])
{
    MyQueue q;
    int item, i;

    for(i = 0; i < 4; i++) {
        cin >> item;
        q.enqueue(item);
    }

    for(i = 0; i < 5; i++) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
