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
    //empty array to copy into
    char newString[256] = "";
    //loop control with input string length
    int length = strlen(inputString);

    for (int i = 0; i < length; i++)

    {
        //character is the current letter in the input word
        char c = inputString[i];

        //example: hello -> length 5
        //5-0 =5, newString[5] = o
        //5-1 = 4 newString[4] = l, etc
        //[3] = l
        //[2] = e
        //[1] = h
        //no 0 index because i starts at 0 instead of 1
        newString[length - i] = c;

    }

    //because the loop always leaves 0 empty, it counts as an empty string, so it always returns an empty string.
    //to fix it, you could do int i = 0; i <= length instead
    strcpy_s(inputString, 128, newString);

    return inputString;

}


int main()
{
    char userString[100];
    std::cout << "Write a string to reverse: \t " ;
    std::cin.getline(userString, 100);
    std::cout << "\nReversed word: " << reverseString(userString) << "\n";

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
