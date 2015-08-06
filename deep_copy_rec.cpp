#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Thing
{
public:
    static map<Thing*, Thing*> mapping;
    Thing *things;
    Thing() {}
    Thing(Thing &obj);
    void add(Thing &obj);
    void operator = (Thing &obj);
    friend ostream & operator << (ostream &out, Thing &obj);
};

map<Thing*, Thing*> Thing :: mapping;

void Thing :: add(Thing &obj)
{
    things = &obj;
}

Thing :: Thing(Thing &obj)
{
    mapping[&obj] = this;
    if (mapping.count(obj.things) < 1) {
        cout << obj.things << "--\n";
        things = new Thing(*obj.things);
        cout << things << "++\n";
    } else {
        cout << obj.things << "--\n";
        things = mapping[obj.things];
        cout << things << "++\n";
    }
}

ostream & operator << (ostream &out, Thing &obj)
{
    out << &obj << endl;
    return out;
}


int main(int argc, char *argv[])
{
    Thing a, b, c;
    a.add(b);
    b.add(c);
    c.add(a);

    Thing new_a = a;

    cout << a;
    cout << b;
    cout << c << endl;

    cout << *c.things;
    cout << *a.things;
    cout << *b.things << endl;

    cout << new_a;
    cout << *new_a.things;
    cout << *new_a.things->things << endl;

    // cout << *a.things;
    // cout << *b.things;
    // cout << *c.things;

    Thing *dd = new Thing();
    dd->things = &a;
    // cout << *dd->things;
    cout << *dd;
    // cout << *new Thing();
    return 0;
}
