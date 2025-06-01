#include <bitset> // for std::bitset
#include <iostream>
#include <format> // C++20
// #include <print> // C++23

/*
* Best practice
* Prefer constant variables over object-like macros with substitution text.
 */
#define MY_NAME "Soso"

void printInt(int x)
{
    std::cout << x << '\n';
}


// The return value of a non-constexpr function is not constexpr
int five()
{
    return 5;
}


int max(int x, int y) // this is a non-constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

constexpr int cmax(int x, int y) // this is a constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    const double gravity { 9.8 };  // preferred use of const before type
    const int sidesInSquare { 4 }; // "east const" style, okay but not preferred

    printInt(5); // 5 will be used as the initializer for x
    printInt(6); // 6 will be used as the initializer for x

    std::cout << "My name is: " << MY_NAME << '\n';

    std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n'; // 5L is type long
    std::cout << 5u << '\n'; // 5u is type unsigned int

    int a { 5 };          // ok: types match
    unsigned int b { 6 }; // ok: compiler will convert int value 6 to unsigned int value 6
    long c { 7 };         // ok: compiler will convert int value 7 to long value 7

    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    float f { 4.1 }; // warning: 4.1 is a double literal, not a float literal

    float f_1 { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
    double d { 4.1 }; // change variable to type double so it matches the literal type double

    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double d_1 { -1.23 };    // the literal can be negative
    double why { 0. };     // syntactically acceptable, but avoid this because it's hard to see the decimal point (prefer 0.0)

    double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
    double protonCharge { 1.6e-19 }; // charge on a proton is 1.6 x 10^-19

    int x{ 012 }; // 0 before the number means this is octal
    std::cout << x << '\n';

    int x_1{ 0xF }; // 0x before the number means this is hexadecimal
    std::cout << x << '\n';

    // Prior to C++14, there is no support for binary literals. However, hexadecimal literals provide us with a useful workaround (that you may still see in existing code bases):
    int bin{}; // assume 16-bit ints
    bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
    bin = 0x0002; // assign binary 0000 0000 0000 0010 to the variable
    bin = 0x0004; // assign binary 0000 0000 0000 0100 to the variable
    bin = 0x0008; // assign binary 0000 0000 0000 1000 to the variable
    bin = 0x0010; // assign binary 0000 0000 0001 0000 to the variable
    bin = 0x0020; // assign binary 0000 0000 0010 0000 to the variable
    bin = 0x0040; // assign binary 0000 0000 0100 0000 to the variable
    bin = 0x0080; // assign binary 0000 0000 1000 0000 to the variable
    bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
    bin = 0x00B3; // assign binary 0000 0000 1011 0011 to the variable
    bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable


    int bin_1{};        // assume 16-bit ints
    bin_1 = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin_1 = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin_1 = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin_1 = 0b11110000; // assign binary 0000 0000 1111 0000 to the variabl

    // Because long literals can be hard to read, C++14 also adds the ability to use a quotation mark (‘) as a digit separator.
    int bin2{0b1011'0010}; // assign binary 1011 0010 to the variable
    long value2{2'132'673'462}; // much easier to read than 2132673462

    int x_2 { 12 };
    std::cout << x_2 << '\n'; // decimal (by default)
    std::cout << std::hex << x_2 << '\n'; // hexadecimal
    std::cout << x_2 << '\n'; // now hexadecimal
    std::cout << std::oct << x_2 << '\n'; // octal
    std::cout << std::dec << x_2 << '\n'; // return to decimal
    std::cout << x_2 << '\n'; // decimal

    // std::bitset<8> means we want to store 8 bits
    std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
    std::bitset<8> bin3{ 0xC5 }; // hexadecimal literal for binary 1100 0101

    std::cout << bin1 << '\n' << bin3 << '\n';
    std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

    std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

    // std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline

    constexpr int x_3 { 3 }; // Because variable x is constexpr, expr must be evaluatable at compile-time

    int a_1 { 5 };       // not const at all
    const int b_1 { a }; // clearly not a constant expression (since initializer is non-const)
    const int c_1 { 5 }; // clearly a constant expression (since initializer is a constant expression)

    constexpr double gravity_1 { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge { age };      // compile error: age is not a constant expression
    // constexpr int f_2 { five() };       // compile error: return value of five() is not constexpr

    int m1 { max(5, 6) };            // ok
    const int m2 { max(5, 6) };      // ok
    // constexpr int m3 { max(5, 6) };  // compile error: max(5, 6) not a constant expression

    int m4 { cmax(5, 6) };           // ok: may evaluate at compile-time or runtime
    const int m5 { cmax(5, 6) };     // ok: may evaluate at compile-time or runtime
    constexpr int m6 { cmax(5, 6) }; // okay: must evaluate at compile-time

    return 0;
}
