#include <cstdlib> // for std::exit()
#include <iostream>

void cleanup()
{
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

/*
 *The std::abort() function causes your program to terminate abnormally. Abnormal termination means the program had some kind of unusual
 *runtime error and the program couldn’t continue to run. For example, trying to divide by 0 will result in an abnormal termination. std::abort()
 *does not do any cleanup.
 */
void abortSample() {
    std::cout << 1 << '\n';
    std::abort();
    // The following statements never execute
    std::cout << 2 << '\n';
}

int main()
{
    // register cleanup() to be called automatically when std::exit() is called
    std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}