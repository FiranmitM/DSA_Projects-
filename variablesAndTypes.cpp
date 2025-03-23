#include <iostream>
int main(){
    char letter = 'B';
    int number = 50;
    float decimalNumber = 2.5f;
    bool isActive = false;
    // Update each variable
    letter = 'Z';
    number += 50;            // Now becomes 100
    decimalNumber *= 2;      // Now becomes 5.0
    isActive = !isActive;    // Toggle from false to true
    std::cout << "Updated Char: " << letter << "\n";
    std::cout << "Updated Int: " << number << "\n";
    std::cout << "Updated Float: " << decimalNumber << "\n";
    std::cout << "Updated Bool: " << isActive << "\n";
    return 0;
}