#include <iostream>
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

void doPrint() {
    std::cout << "In doPrint()\n";
}

void doB() {
    std::cout << "In doB()\n";
}


void doA() {
    std::cout << "Starting doA()\n";

    doB();

    std::cout << "Ending doA()\n";
}

int funcWithReturn() {
    return 42;
}

void printValues(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int add(int x, int y);

int main() {
    // void foo() // Illegal: this function is nested inside function main()
    // {
    //     std::cout << "foo!\n";
    // }

    std::cout << "Starting main()\n";
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    doA(); // Nested functions are not supported
    std::cout << funcWithReturn() << '\n';
    printValues(5, 10);
    std::cout << "Ending main()\n"; // This statement is executed after doPrint() ends

    return EXIT_SUCCESS;
}

int add(int x, int y) // function parameters x and y are local variables
{
    int z{ x + y }; // z is a local variable

    return z;
} // z, y, and x destroyed here
