#include <iostream>

void doNothing(int &) {
}

int five()
{
    return 5;
}

int main() {
    std::cout << 5 << '\n'; // print the literal number `5`
    std::cout << -6.7 << '\n'; // print the literal number `-6.7`
    std::cout << 'H' << '\n'; // print the literal character `H`
    std::cout << "Hello" << '\n'; // print the literal text `Hello

    int x = 5; // define an integer variable named x
    int y{10}; // define variable x and initialize with initial value 10

    std::cout << x << '\n';
    std::cout << y << '\n';

    // Different forms of initialization
    int a; // default-initialization (no initializer)

    // Traditional initialization forms:
    int b = 5; // copy-initialization (initial value after equals sign)
    int c(6); // direct-initialization (initial value in parenthesis)

    // Modern initialization forms (preferred):
    int d{7}; // direct-list-initialization (initial value in braces)
    int e{}; // value-initialization (empty braces)
    int f(5); // direct initialization of value 5 into variable width

    // List-initialization
    /*
     *The modern way to initialize objects in C++ is to use a form of initialization that makes use of curly braces. This is called list-initialization (or uniform initialization or brace initialization).
    */
    int width{5}; // direct-list-initialization of initial value 5 into variable width (preferred)
    int height = {6}; // copy-list-initialization of initial value 6 into variable height (rarely used)

    // Value-initialization and zero-initialization
    /*
     * When a variable is initialized using an empty set of braces, a special form of list-initialization called value-initialization takes place.
     * In most cases, value-initialization will implicitly initialize the variable to zero (or whatever value is closest to zero for a given type).
     * In cases where zeroing occurs, this is called zero-initialization.
    */
    int width_1{}; // value-initialization / zero-initialization to value 0

    // Initializing multiple variables
    int a_1 = 5, b_1 = 6; // copy-initialization
    int c_1(7), d_1(8); // direct-initialization
    int e_1{9}, f_1{10}; // direct-list-initialization
    int i_1{}, j_1{}; // value-initialization

    // The [[maybe_unused]] attribute
    [[maybe_unused]] double pi{3.14159}; // Don't complain if pi is unused
    [[maybe_unused]] double gravity{9.8}; // Don't complain if gravity is unused
    [[maybe_unused]] double phi{1.61803}; // Don't complain if phi is unused

    // define an integer variable named x
    int x_2; // this variable is uninitialized

    doNothing(x_2); // make the compiler think we're assigning a value to this variable

    // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    std::cout << x << '\n';

    std::cout << sizeof(int) << '\n'; // print how many bytes of memory an int value takes

    int a_3{ 2 };             // initialize variable a with literal value 2
    int b_3{ 2 + 3 };         // initialize variable b with computed value 5
    int c_3{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d_3{ b };             // initialize variable d with variable value 5
    int e_3{ five() };        // initialize variable e with function return value 5

    return 0;
}
