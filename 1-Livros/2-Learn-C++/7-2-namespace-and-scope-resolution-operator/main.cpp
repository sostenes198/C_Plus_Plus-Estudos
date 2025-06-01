#include <iostream>
#include "add.h" // for BasicMath::add()
#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e
#include "constants.h"
#include "constants2.h"

int g_x{10};
const int g_y{1}; // const global variable g_y, initialized with a value
constexpr int g_z{2}; // constexpr global variable g_z, initialized with a value

extern const int g_y1{3}; // const globals can be defined as extern, making them external
extern constexpr int g_z1{3};
// constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)

// Quick summary
// Global variable forward declarations (extern w/ no initializer):
extern int g_y2; // forward declaration for non-constant global variable
extern const int g_2; // forward declaration for const global variable
extern constexpr int g_2 = 10; // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_x1; // defines non-initialized external global variable (zero initialized by default)
int g_x2{1}; // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x3{2}; // defines initialized const external global variable
extern constexpr int g_4{3}; // defines initialized constexpr external global variable

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

namespace Foo {
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }

    void printHelloThere() {
        print(); // calls print() in Foo namespace
        ::print(); // calls print() in global namespace
    }


    namespace Goo // Goo is a namespace inside the Foo namespace
    {
        int add(int x, int y) {
            return x + y;
        }
    }
}

void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file

int main() {
    sayHi();

    Foo::printHelloThere(); // call print() in Foo namespace
    ::print(); // call print() in global namespace (same as just calling print() in this case)

    std::cout << BasicMath::add(4, 3) << "\n";
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    std::cout << Foo::Goo::add(5, 6) << "\n";

    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()


    std::cout << Constants::myGravity;

    std::cout << Constants2::myGravity;

    return 0;
}
