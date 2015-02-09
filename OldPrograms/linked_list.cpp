#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node * next;

    Node() { next = NULL; }
    Node(int);
};

class LinkedList
{
    Node * head;

public:
    LinkedList() { head = NULL; }
    void add_node(int);
    void display();
    void reverse();
    void bubble_sort();
    void bubble_sort2();
    void bubble_sort3();
    void exchange_nodes(Node *, Node *);
};

Node :: Node(int value)
{
    info = value;
    next = NULL;
}

void LinkedList :: display()
{
    Node * p = head;
    while(p != NULL) {
        cout << p -> info << " ";
        p = p -> next;
    }
    cout << endl;
}

void LinkedList :: add_node(int value)
{
    if(head) {
        Node * p = head;
        while(p -> next != NULL)
            p = p -> next;
        p -> next = new Node(value);
    } else
        head = new Node(value);
}

void LinkedList :: reverse()
{
    Node *prev, *curr, *next;

    if(!head)
        return;

    prev = NULL;
    curr = head;
    next = curr -> next;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList :: bubble_sort()
{
    Node *p, *q;
    int temp;

    if(!head || !head -> next)
        return;

    for(p = head; p -> next != NULL; p = p -> next) {
        for(q = head; q -> next != NULL; q = q -> next) {
            if(q -> info  >  q -> next -> info) {
                temp = q -> info;
                q -> info = q -> next -> info;
                q -> next -> info = temp;
            }
        }
    }
}

void LinkedList :: exchange_nodes(Node *prev, Node *curr)
{
    Node *next = curr -> next;

    if (prev == curr) {
        curr -> next = next -> next;
        next -> next = curr;
        prev = next;
    } else {
        prev -> next = next;
        curr -> next = next -> next;
        next -> next = curr;
        prev = next;
    }
}

void LinkedList :: bubble_sort3()
{
    Node *p, *q, *prev;
    int temp, length = 0, i, j;

    if(!head || !head -> next)
        return;

    for(p = head; p != NULL; p = p -> next)
        length++;

    for(i = 1; i < length; i++) {
        prev = head;
        for(j = 0, q = head; j < (length - i - 1), q -> next != NULL; j++, q = q -> next) {
            if(q -> info  >  q -> next -> info)
                exchange_nodes(prev, q);
            prev = q;
        }
    }
}

void LinkedList :: bubble_sort2()
{
    Node *p, *q;
    int temp, length = 0, i, j;

    if(!head || !head -> next)
        return;

    for(p = head; p != NULL; p = p -> next)
        length++;

    for(i = 1; i < length; i++) {
        for(j = 0, q = head; j < (length - i - 1), q -> next != NULL; j++, q = q -> next) {
            if(q -> info  >  q -> next -> info) {
                temp = q -> info;
                q -> info = q -> next -> info;
                q -> next -> info = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    LinkedList list;
    int value, i;

    for(i = 0; i < 5; i++) {
        cin >> value;
        list.add_node(value);
    }
    list.display();
    // list.reverse();
    // list.recursive_reverse(NULL, NULL);
    list.bubble_sort3();
    list.display();
    return 0;
}
