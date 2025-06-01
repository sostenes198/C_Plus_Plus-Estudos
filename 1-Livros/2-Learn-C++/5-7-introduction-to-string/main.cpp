#include <string>
#include <iostream>


void getNameSample() {
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
}

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

std::string getName()
{
    std::string s { "Alex" };
    return s;
}



int main() {
    /*
    *   If std::string doesn’t have enough memory to store a string, it will request additional memory (at runtime) using a form of memory allocation
    *   known as dynamic memory allocation. This ability to acquire additional memory is part of what makes std::string so flexible, but also comparatively slow.
    *   We cover dynamic memory allocation in a future chapter.
    */
    std::string str = "Hello World!";

    std::string name{"Alex"}; // initialize name with string literal "Alex"
    name = "John"; // change name to "John"

    std::string myID{"45"}; // "45" is not the same as integer 45!

    std::cout << "My name is: " << name << '\n';

    std::string empty{};
    std::cout << '[' << empty << ']';

    std::cout << name << " has " << name.length() << " characters\n";
    std::cout << name << " has " << std::ssize(name) << " characters\n";

    const int length{static_cast<int>(name.length())};
    const int len { static_cast<int>(std::ssize(name)) };

    std::cout << length << "\n";
    std::cout << len << "\n";

    // getNameSample();

    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal

    std::string s{ "Hello, world!" }; // s makes a copy of its initializer
    printString(s);

    std::string_view s_1{ "Hello, world!" }; // now a std::string_view
    printSV(s_1);


    printString(static_cast<std::string>(s_1)); // okay: we can explicitly cast a std::string_view to a std::string

    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    constexpr std::string_view s_3{ "Hello, world!" }; // s is a string symbolic constant
    std::cout << s_3 << '\n'; // s will be replaced with "Hello, world!" at compile-time

    std::string_view sv{};

    { // create a nested block
        std::string s{ "Hello, world!" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    std::string_view name_1 { getName() }; // name initialized with return value of function
    std::cout << name_1 << '\n'; // undefined behavior

    // Revalidating an invalid std::string_view
    std::string s_2 { "Hello, world!" };
    std::string_view sv_1 { s }; // sv is now viewing s

    s_2 = "Hello, universe!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv_1 << '\n';   // undefined behavior

    sv_1 = s_2;                    // revalidate sv: sv is now viewing s again
    std::cout << sv_1 << '\n';   // prints "Hello, universe!"

    return 0;
}
