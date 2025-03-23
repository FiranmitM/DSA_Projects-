
#include <iostream>
#include <string>

int main(){
    int value = 10;
    std::cout << "Initial value: " << value << std::endl;
    
    value += 5; // value becomes 15
    std::cout << "After adding 5: " << value << std::endl;
    
    value -= 3; // value becomes 12
    std::cout << "After subtracting 3: " << value << std::endl;
    
    // Ternary operator to check if value > 10
    std::string message = (value > 10) ? "Value is greater than 10" : "Value is not greater than 10";
    std::cout << message << std::endl;
    
    return 0;
}
