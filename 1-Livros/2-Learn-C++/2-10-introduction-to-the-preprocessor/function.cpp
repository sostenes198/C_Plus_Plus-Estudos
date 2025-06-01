#include <iostream>

/* Even though PRINT was defined in main.cpp, that doesn’t have any impact on any of the code in function.cpp
 * (PRINT is only #defined from the point of definition to the end of main.cpp). This will be of consequence when we discuss header guards in a future lesson.
 */
void doSomething() {
#ifdef PRINT
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
}
