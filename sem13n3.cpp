#include <iostream>
#include <string>
#include <vector>

int main() {
    int* intPtr = new int(123);
    std::string* stringPtr = new std::string("Cats and Dogs");
    int* intArray = new int[5]{10, 20, 30, 40, 50};
    std::vector<int>* vectorPtr = new std::vector<int>({10, 20, 30, 40, 50});
    std::string* stringArray = new std::string[3]{"Cat", "Dog", "Mouse"};

    std::cout << "int: " << *intPtr << std::endl;
    std::cout << "std::string: " << *stringPtr << std::endl;
    std::cout << "int array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "std::vector: ";
    for (const auto& elem : *vectorPtr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "std::string array: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    delete intPtr;
    delete stringPtr;
    delete[] intArray;
    delete vectorPtr;
    delete[] stringArray;

    return 0;
}