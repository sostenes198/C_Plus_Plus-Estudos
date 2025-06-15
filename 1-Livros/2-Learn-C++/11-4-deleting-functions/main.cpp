#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T>
void printInt(T x) = delete;

int main() {
    printInt(5);    // okay: prints 5
    // printInt('a');  // prints 97 -- does this make sense?
    // printInt(true); // print 1 -- does this make sense?

    return 0;
}
