#include "Alex.h" // copies #define MY_NAME from Alex.h here
#include <iostream>
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE


#define MY_NAME "Sostenes"
#define PRINT_JOE
#define FOO 9 // Here's a macro substitution

/* Even though PRINT was defined in main.cpp, that doesn’t have any impact on any of the code in function.cpp
 * (PRINT is only #defined from the point of definition to the end of main.cpp). This will be of consequence when we discuss header guards in a future lesson.
 */
#define PRINT

void doSomething(); // forward declaration for function doSomething()

int main() {
    std::cout << "My name is: " << MY_NAME << '\n';

#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    // One more common use of conditional compilation involves using #if 0 to exclude a block of code from being compiled (as if it were inside a comment block):
#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif // until this point

    // To temporarily re-enable code that has been wrapped in an #if 0, you can change the #if 0 to #if 1:
#if 1 // Don't compile anything starting here
    std::cout << "Joe\n";
    std::cout << "Kessie\n";
#endif // until this point

#ifdef FOO // This FOO does not get replaced with 9 because it’s part of another preprocessor directive
    std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
#endif

    std::cout << "My name is: " << MY_NAME_ALEX << '\n'; // preprocessor replaces MY_NAME with "Alex"

    doSomething();

    return EXIT_SUCCESS;
}
