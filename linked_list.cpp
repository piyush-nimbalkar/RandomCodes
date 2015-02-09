#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *next;

    Node() { next = NULL; }
    Node(int);
    // ~Node() { delete next; }
};

Node :: Node(int value)
{
    data = value;
    next = NULL;
}

class LinkedList
{
    Node *head;
public:
    LinkedList() { head = NULL; }
    void add_node(int);
    void display();
    void reverse();
    void bubble_sort();
    ~LinkedList() { delete head; }
};

void LinkedList :: add_node(int value)
{
    Node *ptr = head;

    if (!head)
        head = new Node(value);
    else {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new Node(value);
    }
}

void LinkedList :: reverse()
{
    Node *prev = NULL, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList :: bubble_sort()
{
    Node *p, *q;

    if (!head)
        return;

    for (p = head; p->next; p = p->next) {
        for (q = head; q->next; q = q->next) {
            if (q->data > q->next->data) {
                q->data       = q->data + q->next->data;
                q->next->data = q->data - q->next->data;
                q->data       = q->data - q->next->data;
            }
        }
    }
}

void LinkedList :: display()
{
    Node *ptr;
    for (ptr = head; ptr; ptr = ptr->next)
        cout << ptr->data << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    LinkedList list;
    int size, data;

    cout << "Enter Size: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> data;
        list.add_node(data);
    }

    list.display();
    list.bubble_sort();
    list.display();
    list.reverse();
    list.display();
    return 0;
}
