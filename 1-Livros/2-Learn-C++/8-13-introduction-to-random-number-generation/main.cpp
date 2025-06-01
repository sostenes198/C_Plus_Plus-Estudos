#include <iostream>
#include <random> // for std::mt19937
#include <chrono> // for std::chrono

int plusOne() {
    static int s_state{3}; // only initialized the first time this function is called

    // Generate the next number

    ++s_state; // first we modify the state
    return s_state; // then we use the new state to generate the next number in the sequence
}

unsigned int g_state{0};

void seedPRNG(unsigned int seed) {
    g_state = seed;
}

// For illustrative purposes only, don't use this
unsigned int LCG16() // our PRNG
{
    // We modify the state using large constants and intentional overflow to make it hard
    // for someone to casually determine what the next number in the sequence will be.

    g_state = 8253729 * g_state + 2396403; // first we modify the state
    return g_state % 32768; // then we use the new state to generate the next number in the sequence
}

void print10() {
    // Print 10 random numbers
    for (int count{1}; count <= 10; ++count) {
        std::cout << LCG16() << '\t';
    }

    std::cout << '\n';
}

void random_number_1() {
    // Generating random numbers in C++ using Mersenne Twister
    std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
        std::cout << mt() << '\t'; // generate a random number

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }
}

void random_number_2() {
    // Rolling a dice using Mersenne Twister
    std::mt19937 mt{};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
}

void random_number_3() {
    // Seeding with the system clock
    // Seed our Mersenne Twister using steady_clock
    std::mt19937 mt{
        static_cast<std::mt19937::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()
        )
    };

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
}

void random_number_4() {
    // Seeding with the random device
    std::mt19937 mt{std::random_device{}()};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
}

void random_number_5() {
    std::random_device rd{};
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    // get 8 integers of random numbers from std::random_device for our seed
    std::mt19937 mt{ss}; // initialize our Mersenne Twister with the std::seed_seq

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count) {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
}

int main() {
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';

    unsigned int x{};
    std::cout << "Enter a seed value: ";
    std::cin >> x;

    seedPRNG(x); // seed our PRNG
    print10(); // generate 10 random values


    random_number_1();
    random_number_2();
    random_number_3();

    return 0;
}
