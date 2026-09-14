// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstring>
#include <iostream>

int main()
{
    //initialize first word, count letters & print
    char wordOne[40]{ "supercalifragilistic" };
    std::cout << "letters in Supercalifragiilistic: " << strlen(wordOne) << "\n";

    //initialize second word, concatenate
    char wordTwo[] = "expialidocious";

    strcat_s(wordOne, wordTwo);
    std::cout << wordOne << "\n";
    
    //bool for if end is reached
    bool foundLetter = true;
    //index the loop is at
    int checkedIndex = 0;
    //amount of times i has been found
    int iCount = 0;

    //while it has not reached the end
    //check for the letter, set the new starting index, add to i count
    //check again starting after the last point
    while (foundLetter == true) 
    {
        char* indexFound = strchr(wordOne + checkedIndex, 'i');

        if (indexFound != NULL)
        {
            checkedIndex = indexFound - wordOne + 1;
            iCount++;
        }
        else
        {
            foundLetter = false;
        }
    }
    // print the count
    std::cout << "Number of i's in Supercalifragilisticexpialidocious: " << iCount;

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
