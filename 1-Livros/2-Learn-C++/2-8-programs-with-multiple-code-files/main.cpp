#include <iostream>
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

using namespace std;

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

// Sample duplicated in a.cpp
// void myFcn(int x) {
//     cout << 2 * x;
// }

void foo(); // okay: function forward declaration
int x; // compiles but strongly discouraged: non-const global variable definition (without initializer)
int y{5}; // compiles but strongly discouraged: non-const global variable definition (with initializer)
// x = 5;         // compile error: executable statements are not allowed in namespaces

int main() {
    cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return EXIT_SUCCESS;
}

void goo(); // okay: A function forward declaration
