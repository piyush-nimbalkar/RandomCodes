#include <iostream>
#include <list>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() { next = NULL; }
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
    Node* add_next(int _data)
    {
        next = new Node(_data);
        return next;
    }
};



Node* remove_items(Node *head)
{
    Node *p = head;
    while(p) {
        if (p == head && p->data == 5) {
            p = p->next;
            delete(head);
            head = p;
        } else
            break;
    }
    if (head == NULL)
        return NULL;

    Node *q = p->next;
    while(q) {
        if (q->data == 5) {
            p->next = q->next;
            delete(q);
        } else {
            p = p->next;
        }
        q = p->next;
    }
    return head;
}

int main(int argc, char *argv[])
{
    Node *head = new Node(5);
    Node *a = head->add_next(5);
    Node *b = a->add_next(2);
    Node *c = b->add_next(5);
    Node *d = c->add_next(3);
    Node *e = d->add_next(5);

    Node * new_head = remove_items(head);

    for (Node *t = new_head; t; t = t->next)
        cout << t->data << "  ";
    cout << endl;

    return 0;
}

// int main(int argc, char *argv[])
// {
    // int size, num;
    // list<int> input;

    // cin >> size;
    // for (int i = 0; i < size; i++) {
        // cin >> num;
        // input.push_back(num);
    // }

    // list<int>::iterator it = input.begin();
    // while (it != input.end()) {
        // if (*it == 5)
            // it = input.erase(it);
        // else
            // it++;
    // }

    // for (list<int>::iterator j = input.begin(); j != input.end(); j++)
        // cout << *j << "  ";
    // cout << endl;

    // return 0;
// }
