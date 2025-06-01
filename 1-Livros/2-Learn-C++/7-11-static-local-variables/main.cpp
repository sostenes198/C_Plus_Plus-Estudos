#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

int getInteger()
{
    static bool s_isFirstCall{ true };

    if (s_isFirstCall)
    {
        std::cout << "Enter an integer: ";
        s_isFirstCall = false;
    }
    else
    {
        std::cout << "Enter another integer: ";
    }

    int i{};
    std::cin >> i;
    return i;
}

int main() {

    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    int a{ getInteger() };
    int b{ getInteger() };
    std::cout << a << " + " << b << " = " << (a + b) << '\n';


    return 0;
}
