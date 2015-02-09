#include <iostream>

using namespace std;

template <class T1, class T2>
class complex
{
    T1 a;
    T2 b;

public:
    complex() {}
    complex(T1, T2);
    complex add(T1, T2);
    void display();
};

template <class T1, class T2>
complex<T1, T2> :: complex(T1 real, T2 imag)
{
    a = real;
    b = imag;
}

template <class T1, class T2>
complex<T1, T2> complex<T1, T2> :: add(T1 real, T2 imag)
{
    complex <T1, T2> c;
    c.a = a + real;
    c.b = b + imag;
    return c;
}

template <class T1, class T2>
void complex<T1, T2> :: display()
{
    cout << a << " + i" << b << endl;
}

int main(int argc, char *argv[])
{
    complex <float, int> c1(2.7236, 4);
    complex <float, int> c2;
    c2 = c1.add(3.3423, 3);
    c2.display();
    return 0;
}
