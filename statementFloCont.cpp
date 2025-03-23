#include <iostream>

int main(){
    int x = 5;
    
    // If-else statement: checks whether x is positive
    if (x > 0)
        std::cout << "x is positive" << std::endl;
    else
        std::cout << "x is not positive" << std::endl;
    
    // Switch statement: executes code based on the value of x
    switch (x) {
        case 1:
            std::cout << "x is 1" << std::endl;
            break;
        case 5:
            std::cout << "x is 5" << std::endl;
            break;
        default:
            std::cout << "x is neither 1 nor 5" << std::endl;
    }
    
    // For loop: prints a countdown from 3 to 1
    std::cout << "Countdown: ";
    for (int i = 3; i > 0; i--) {
        std::cout << i << " ";
    }
    std::cout << "liftoff!" << std::endl;
    
    return 0;
}
