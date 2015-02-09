#include <iostream>

using namespace std;

class complex
{
    int real, imag;

public:
    complex() {}
    complex(int, int);
    complex operator+(complex);
    void display();
};

complex :: complex(int r, int i)
{
    real = r;
    imag = i;
}

complex complex :: operator+(complex c)
{
    complex result;
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

void complex :: display()
{
    cout << real << " + " << imag << "i" << endl;
}

main()
{
    complex A(3, 4), B(5, 6), C(0, 0);
    C = A + B;
    C.display();
    return 0;
}
