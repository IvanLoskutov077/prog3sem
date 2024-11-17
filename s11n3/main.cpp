#include <iostream>
#include "number.hpp"
#include "integer.hpp"

using std::cout, std::endl;

int main()
{
    Number x = 12345678;
    Number y = 0;
    cout << "Number x: " << x << endl;
    cout << "Number y: " << y << endl;

    Number a("12345678");
    Number b("987654321");
    cout << "Number a: " << a << endl;
    cout << "Number b: " << b << endl;
    cout << "a + b: " << a + b << endl;
    cout << "a * b: " << a * b << endl;
    cout << "a is even: " << (a.isEven() ? "true" : "false") << endl;

    Integer c = 12345678;
    Integer d = 0;
    cout << "Integer c: " << c << endl;
    cout << "Integer d: " << d << endl;

    Integer e("12345678");
    Integer f("987654321");
    cout << "Integer e: " << e << endl;
    cout << "Integer f: " << f << endl;
    cout << "e + f: " << e + f << endl;
    cout << "e * f: " << e * f << endl;
    cout << "e is even: " << (e.isEven() ? "true" : "false") << endl;

    cout << "Factorial of 1000: " << Number::factorial(1000) << endl;
    cout << "Factorial of 1000: " << Integer::factorial(1000) << endl;

    cout << "Fibonacci number 1000: " << Number::fibonacci(1000) << endl;
    cout << "Fibonacci number 1000: " << Integer::fibonacci(1000) << endl;

    return 0;
}