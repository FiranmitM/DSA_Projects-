#include <iostream>
using namespace std;

int main() {
    int num = 4; 
    int factorial = 1; 

    for (int i = 1; i <= num; i++) {
        factorial *= i; 
    }
    

    cout << "Factorial of " << num << " is: " << factorial << endl;

    return 0;
}
