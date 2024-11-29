#include <iostream>

class Cat {
private:
    int& miceCaught;
    
public:
    Cat(int& miceCaught) : miceCaught(miceCaught) {}

    void catchMice(int count) {
        miceCaught += count;
    }
};

int main() {
    int miceCaughtA = 0;
    int miceCaughtB = 0;

    Cat alice(miceCaughtA), alex(miceCaughtA), anna(miceCaughtA);
    Cat bob(miceCaughtB), bella(miceCaughtB);

    alice.catchMice(2);
    alex.catchMice(1);
    bella.catchMice(4);
    bob.catchMice(2);
    anna.catchMice(1);
    bella.catchMice(1);
    alex.catchMice(4);
    bella.catchMice(5);
    alice.catchMice(2);

    std::cout << miceCaughtA << std::endl; // Должно напечатать 10
    std::cout << miceCaughtB << std::endl; // Должно напечатать 12

    return 0;
}