// FirstStepsInCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool is_even(int x) {
    bool result = (x % 2) == 0;
    return result;
}
int main()
{
    int number = 7;
    std::cout << "First Steps in CPP\n";
    std::cout << "Is " << number << " even?\n";
    bool number_is_even = is_even(number);
    if ( number_is_even ) {
        std::cout << "Yes.\n";
    } else {
		std::cout << "No.\n";
	}
    std::cout << "Welcome to Amsterdam\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
