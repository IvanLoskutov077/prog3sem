#include <iostream>
#include <string>

using namespace std;

void addBrackets(string &a) {
    a = '[' + a + ']';
}

int main(void) {
    string a = "cat";
    addBrackets(a);
    cout << a << endl;
    
    addBrackets(a);
    cout << a << endl;
}