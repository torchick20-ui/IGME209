// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<time.h>

void generateRandom(int numberOfRandoms)
{
    srand(time(NULL));

    //declared outside the loop so the breakpoint locals read correctly
    int currentRand;

    //rand loop
    for (int loopCount = 1; loopCount <= numberOfRandoms; loopCount++)
    {
        currentRand = rand();
        std::cout << "Random number # " << loopCount << " is " << currentRand << "\n";
    }
    //breakpoint at the end of the loop so it is after the number generates
}

char* reverseString(char inputString[])

{

    char newString[256] = "";

    int length = strlen(inputString);

    for (int i = 0; i < length; i++)

    {

        char c = inputString[i];

        newString[length - i] = c;

    }

    strcpy_s(inputString, 128, newString);

    return inputString;

}


int main()
{
    char userString[100];
    std::cout << "Write a string to reverse: \t " ;
    //std::cin.getline(, userString) >> userString;

    reverseString(userString);
    // get user input from the keyboard
    generateRandom(25);
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
