nclude <cstddef>  // for std::size_t
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT
#include <limits>

void print(int x) // print now takes an int parameter
{
    std::cout << x << '\n';
}

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit
    std::cout << x << '\n';

    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
    std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
    std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

    int x_1 { 5 };
    std::size_t s { sizeof(x_1) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double
    // Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.

    double zero { 0.0 };

    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double z1 { 0.0 / posinf }; // positive zero
    std::cout << z1 << '\n';

    double z2 { -0.0 / posinf }; // negative zero
    std::cout << z2 << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    bool b1 { true };
    bool b2 { false };
    b1 = false;
    bool b3 {}; // default initialize to false

    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << std::noboolalpha; // You can use std::noboolalpha to turn it back off.

    std::cout << true << '\n';
    std::cout << false << '\n';

    if (x == 0)
        std::cout << "The value is zero\n";
    else if (x > 0)
        std::cout << "The value is non zero\n";
    else
        std::cout << "The value is less than zero\n";

    char ch1{ 'a' }; // (preferred)
    std::cout << ch1 << '\n'; // cout prints character 'a'

    char ch2{ 98 }; // code point for 'b' (not preferred)
    std::cout << ch2 << '\n'; // cout prints a character ('b')

    print(static_cast<int>(5.5)); // explicitly convert double value 5.5 to an int

    char ch{ 97 }; // 97 is ASCII code for 'a'
    // print value of variable ch as an int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

    unsigned int u1 { 5 };
    // Convert value of u1 to a signed int
    int s1 { static_cast<int>(u1) };
    std::cout << s1 << '\n'; // prints 5

    int s2 { 5 };
    // Convert value of s2 to an unsigned int
    unsigned int u2 { static_cast<unsigned int>(s2) };
    std::cout << u2 << '\n'; // prints 5

    std::int8_t myInt{65};      // initialize myInt with value 65
    std::cout << myInt << '\n'; // you're probably expecting this to print 65

    std::int8_t myInt_1{65};
    std::cout << static_cast<int>(myInt_1) << '\n'; // will always print 65

    return 0;
}
