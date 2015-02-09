// All subsets of a Set

#include <iostream>
#include <list>

using namespace std;

typedef list<list<int> > set_list;

set_list subsets(list<int> master)
{
    set_list set, new_set;
    if (master.empty()) {
        list<int> zero(1, 0);
        set.push_front(zero);
        return set;
    }

    int first = master.front();
    master.pop_front();
    new_set = set = subsets(master);
    for(set_list :: iterator it = set.begin(); it != set.end(); it++) {
        if (it -> front() == 0)
            it -> pop_front();
        it -> push_front(first);
        new_set.push_front(*it);
    }
    return new_set;
}

void display(set_list l)
{
    for(set_list :: iterator t = l.begin(); t != l.end(); t++) {
        for (list<int>::iterator it = t -> begin(); it != t -> end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4};
    list<int> master(array, array + 4);

    set_list set = subsets(master);
    display(set);
}
