#include <iostream>
#include <cmath> // for std::sqrt
#include "add.h"
#include "max.h" // import template definition for max<T>(T, T)

template<typename T>
T max(T x, T y) {
    std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

int max(int x, int y) {
    std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

template<typename T>
T addOne(T x) {
    return x + 1;
}


// Beware function templates with modifiable static local variables
// Static local variables, we discussed static local variables, which are local variables with static duration (they persist for the lifetime of the program).
// When a static local variable is used in a function template, each function instantiated from that template will have a separate version of the static local variable.
// This is rarely a problem if the static local variable is const. But if the static local variable is one that is modified, the results may not be as expected.
// Here's a function template with a static local variable that is modified
template<typename T>
void printIDAndValue(T value) {
    static int id{0};
    std::cout << ++id << ") " << value << '\n';
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
// const char* will match a string literal
template<>
const char *addOne(const char *x) = delete;

template<typename T>
void print(T val, int times = 1) {
    while (times--) {
        std::cout << val;
    }
}

template<typename T>
void printIDAndValue(T value);

template<>
void printIDAndValue<int>(int value) {
    static int id{0};
    std::cout << ++id << ") " << value << '\n';
}

template<>
void printIDAndValue<double>(double value) {
    static int id{0};
    std::cout << ++id << ") " << value << '\n';
}

template<typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

// template<int N> // declare a non-type template parameter of type int named N
// void print() {
//     std::cout << N << '\n'; // use value of N here
// }

template<double D> // requires C++20 for floating point non-type parameters
double getSqrt() {
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    if constexpr (D >= 0) // ignore the constexpr here for this example
        return std::sqrt(D); // strangely, std::sqrt isn't a constexpr function (until C++26)

    return 0.0;
}

template<auto N> // deduce non-type template parameter from template argument
void print() {
    std::cout << N << '\n';
} // function template forward declaration

void foo(); // forward declaration for function foo


void sample1() {
    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    std::cout << max<>(1, 2) << '\n'; // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n'; // calls max(int, int)
}

void sample2() {
    // std::cout << addOne("Hello, world!") << '\n'; // compile error
}

void sample3() {
    std::cout << max(2, 3.5) << '\n'; // resolves to max<int, double>
}

void sample4() {
    print<5>();
}

void sample5() {
    std::cout << addOneMultipleFiles(5) << '\n';
}

void sample6() {
    foo();
}


int main() {
    sample1();
    sample2();
    sample3();
    sample4();
    sample5();
    return 0;
}
