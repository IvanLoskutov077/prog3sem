#include <iostream>
#include <string>

using namespace std;

string repeat(int n) {
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += to_string(n);
    }
    return res;
}

int main(void) {
    cout << repeat(5) << endl;
    cout << repeat(10) << endl;
    cout << repeat(-1) << endl;
}