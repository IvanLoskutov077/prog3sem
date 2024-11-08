#include <iostream>
#include <string>

bool isDomainName(const std::string& str) {
    return str.substr(0, 4) == "www." && str.substr(str.size() - 4) == ".com";
}

int main() {
    std::cout << isDomainName("www.google.com") << std::endl; 
    std::cout << isDomainName("abc") << std::endl; 
    std::cout << isDomainName("hello.com") << std::endl;
    return 0;
}