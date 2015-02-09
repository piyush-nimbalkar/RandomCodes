#include <iostream>

using namespace std;


class Test
{
    int *ptr;
    int number;
public:
    Test() { }
    Test(Test & obj);
    Test(int);
    void display();
    void change(int);
};

Test :: Test(Test & obj)
{
    ptr = obj.ptr;
    number = obj.number;
}

Test :: Test(int num)
{
    number = num;
    ptr = &number;
}

void Test :: change(int num)
{
    // number = num;
    *ptr = num;
}

void Test :: display()
{
    cout << number << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
}


int main(int argc, char *argv[])
{
    Test a(10), b;
    a.display();
    b = a;
    b.change(30);
    b.display();
    a.display();
    return 0;
}
