#include <iostream>

int main() {
    std::cout << "Hello" << " world!" << std::endl; // std::cout is buffered
    std::cout << "New Line" << std::endl; // Using std::endl is often inefficient, as it actually does two jobs: it outputs a newline (moving the cursor to the next line of the console), and it flushes the buffer (which is slow). If we output multiple lines of text ending with std::endl, we will get multiple flushes, which is slow and probably unnecessary.
    std::cout << "New Line Without flush" << "\n"; // Using std::endl is often inefficient, as it actually does two jobs: it outputs a newline (moving the cursor to the next line of the console), and it flushes the buffer (which is slow). If we output multiple lines of text ending with std::endl, we will get multiple flushes, which is slow and probably unnecessary.

    std::cout << "Enter an integer number: "; // ask user for a number
    int num{};
    std::cin >> num;
    num = num * 2; // double num's value, then assign that value back to num10
    int doubleNum{ num * 2 }; // define a new variable and initialize it with num * 2
    std::cout << "Double that number is: " << doubleNum << '\n';
    std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it

    return 0;
}
