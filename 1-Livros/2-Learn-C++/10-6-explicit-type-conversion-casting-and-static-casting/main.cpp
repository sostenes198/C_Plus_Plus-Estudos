#include <iostream>
#include "mytypes.h"


void foo()
{
}

auto add(int x, int y)
{
    return x + y;
}

// In the function, the two return statements return values of different types, so the compiler will give an error.
// auto someFcn(bool b)
// {
//     if (b)
//         return 5; // return type int
//     else
//         return 6.7; // return type double
// }

void sample1() {
    char c{'a'};

    std::cout << static_cast<int>(c) << '\n';
}

void sample2() {
    int x{10};
    int y{4};

    // static cast x to a double so we get floating point division
    std::cout << static_cast<double>(x) / y << '\n'; // prints 2.5
}

void sample3() {
    using Distance = double; // define Distance as an alias for type double

    Distance milesToDestination{3.4}; // defines a variable of type double

    std::cout << milesToDestination << '\n'; // prints a double value
}

void sample4() {
    Miles distance { 5 }; // distance is actually just a long
    Speed mhz  { 3200 };  // mhz is actually just a long

    // The following is syntactically valid (but semantically meaningless)
    distance = mhz;
}

void sample5() {
    auto a = 10;           // The compiler is unable to deduce the type of a
    auto b { };       // The compiler is unable to deduce the type of b
    // auto c { foo() }; // Invalid: c can't have type incomplete type void
}

void sample6() {
    const int a { 5 }; // a has type const int
    auto b { a };      // b has type int (const dropped)
}

void sample7() {
    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
}

void sample8() {
    constexpr double a { 3.4 };  // a has type const double (constexpr not part of type, const is implicit)

    auto b { a };                // b has type double (const dropped)
    const auto c { a };          // c has type const double (const dropped but reapplied)
    constexpr auto d { a };      // d has type const double (const dropped but implicitly reapplied by constexpr)
}

int main() {
    sample1();
    sample2();
    sample3();
    sample4();
    sample5();
    sample6();
    sample7();

    return 0;
}
